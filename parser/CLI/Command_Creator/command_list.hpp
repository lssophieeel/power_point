#pragma once

#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>
#include <string>
#include <iostream>

#include "command_factory.hpp"
#include "../parser/tokenizer.hpp"
#include "include_document.hpp"

struct option_list {
    std::unordered_map<std::string, std::pair<std::vector<Token::DataType>, int>> expected_options;
};

struct command_list {
    std::unordered_map<std::string, option_list> get_commands() {
        std::unordered_map<std::string, option_list> commands;

        commands["add_shape_rectangle"] = {
            {
                {"-size", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };
        command_factory::get_instance().add_command<add_shape_rectangle>("add_shape_rectangle");

        commands["add_shape_circle"] = {
            {
                {"-size", {{Token::DataType::INT}, 1}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };
        command_factory::get_instance().add_command<add_shape_circle>("add_shape_circle");

        commands["add_shape_square"] = {
            {
                {"-size", {{Token::DataType::INT}, 1}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };
        command_factory::get_instance().add_command<add_shape_square>("add_shape_square");

        commands["add_text"] = {
            {
                {"-text", {{Token::DataType::STRING}, 1}},
                {"-size", {{Token::DataType::INT}, 1}},
                {"-pos", {{Token::DataType::INT, Token::DataType::INT}, 2}}
            }
        };
        command_factory::get_instance().add_command<add_text>("add_text");

        commands["add_slide"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}}
            }
        };
        command_factory::get_instance().add_command<add_slide>("add_slide");

        commands["edit_slide"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}},
                {"-color", {{Token::DataType::STRING}, 1}}
            }
        };
        command_factory::get_instance().add_command<edit_slide>("edit_slide");

        commands["remove_shape"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}}
            }
        };
        command_factory::get_instance().add_command<remove_shape>("remove_shape");

        commands["remove_slide"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}}
            }
        };
        command_factory::get_instance().add_command<remove_slide>("remove_slide");

        commands["play"] = {
            {}
        };
        command_factory::get_instance().add_command<play>("play");

        commands["stop"] = {
            {}
        };
        command_factory::get_instance().add_command<stop>("stop");

        commands["help"] = {
            {}
        };
        command_factory::get_instance().add_command<help>("help");

        commands["show_slide"] = {
            {
                {"-index", {{Token::DataType::INT}, 1}}
            }
        };
        command_factory::get_instance().add_command<show_slide>("show_slide");
    
        return commands;
    }

    std::unordered_set<std::string> get_valid_colors() {
        std::unordered_set<std::string> valid_colors = {"red", "blue", "green", "yellow", "black", "white", "orange", "purple", "pink"};
        return valid_colors;
    }
};
