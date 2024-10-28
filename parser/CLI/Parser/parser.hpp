#pragma once 

#include "tokenizer.hpp"
#include "syntax_analyzer.hpp"
#include "semantic_analyzer.hpp"
#include "../command_creator/command_factory.hpp"

#include <string>
#include <variant>

class parser { 
public:
    static parser& get_instance();
    void parse_command(std::string& command);
    void print_options();

    parser(const parser&) = delete;
    void operator=(const parser&) = delete;

private:
    parser();
    static parser* instance;

    std::string command_name;
    std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>> options_map;
    std::vector<token> token_vec;
    void print_tokens();

    tokenizer tokenizer;
    syntax_analyzer syntax;
    semantic_analyzer semantic;

    command_factory factory;

    token* token_ptr;
};
