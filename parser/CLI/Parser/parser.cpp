#include "parser.hpp"

parser* parser::instance = nullptr;

parser::parser() { }

parser& parser::get_instance() {
    if (instance == nullptr) {
        instance = new parser();
    }
    return *instance;
}

void parser::parse_command(std::string& command) {
    command_name.clear();
    options_map.clear();
    token_vec.clear();

    std::string input;
    std::istringstream stream(command);
    while (stream >> input) {
        token token;
        token = tokenizer.tokenize(input, token);
        token_vec.push_back(token);
    }

    token end_token;
    end_token.set_end();
    token_vec.push_back(end_token);

    print_tokens();
    if (!syntax.analyze(token_vec)) {
        return;
    }

    auto token_it = token_vec.begin();

    try {
        while (token_it != token_vec.end() && token_it->type != token::token_type::end) {
            switch (token_it->type) {
                case token::token_type::word: {
                    command_name += std::get<std::string>(token_it->data);
                    ++token_it;
                    break;
                }
                case token::token_type::shape_option: {
                    command_name += std::get<std::string>(token_it->data);
                    ++token_it;
                    break;
                }
                case token::token_type::option: {
                    std::string option = std::get<std::string>(token_it->data);
                    ++token_it;

                    std::vector<std::variant<int, double, std::string>> values;
                    while (token_it != token_vec.end() && token_it->type == token::token_type::value) {
                        values.push_back(token_it->data);
                        ++token_it;
                    }

                    options_map[option] = values;
                    break;
                }
                case token::token_type::end:
                    break;
                default:
                    break;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "unknown error\n";
    }

    if (!semantic.analyze(command_name, options_map)) {
        std::cout << "semantic failed\n";
        return;
    }

    print_options();
    command_factory::get_instance().set_data(command_name, options_map);
}

void parser::print_options() {
    std::cout << "printing options:\n";
    for (const auto& pair : options_map) {
        std::cout << pair.first << ": ";
        for (const auto& value : pair.second) {
            std::visit([](const auto& val) { std::cout << val << " "; }, value);
        }
        std::cout << std::endl;
    }
    std::cout << "command name: " << command_name << std::endl;
}

void parser::print_tokens() {
    for (const auto& it : token_vec) {
        switch (it.type) {
            case token::token_type::option:
                std::cout << "option\n";
                break;
            case token::token_type::shape_option:
                std::cout << "shape option\n";
                break;
            case token::token_type::word:
                std::cout << "word\n";
                break;
            case token::token_type::end:
                std::cout << "end\n";
                break;
            case token::token_type::value:
                std::cout << "value\n";
                break;
            default:
                break;
        }
    }
    std::cout << std::endl;
}
