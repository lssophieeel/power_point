#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include <variant>

struct token {
public:
    enum class TokenType {
        WORD, OPTION, SHAPE_OPTION, VALUE, END
    } type;
    enum class DataType {
        INT, DOUBLE, STRING
    } data_type;
    std::variant<int, double, std::string> data;

    DataType detect_data_type(const std::string& input) {
        if (input.find('.') != std::string::npos) {
            try {
                data = std::stod(input);
                return DataType::DOUBLE;
            }
            catch (std::invalid_argument&) {
                data = input;
                return DataType::STRING;
            }
        }
        try {
            data = std::stoi(input);
            return DataType::INT;
        }
        catch (std::invalid_argument&) {
            data = input;
            return DataType::STRING;
        }
    }

    void set_END() {
        this->type = token::TokenType::END;
        this->data_type = token::DataType::STRING;
    }
};

class Tokenizer {
public:
    Tokenizer() = default;
    token tokenizer(std::string command_stream, token& token);
    std::vector<token> get_tokens() const;
    void print(const token& token);

private:
    std::regex word_regex{"[a-zA-Z]+"};
    std::regex shape_option_regex{"-rectangle|-square|-circle"};
    std::regex option_regex{"-[a-zA-Z]+"};
    std::regex value_regex{"^-?\\d+(\\.\\d+)?$|^\"[a-zA-Z]+\"$"};
};
