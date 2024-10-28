#pragma once

#include <functional>
#include <memory>
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>
#include <iostream>

#include "../../commands/command.hpp"

class command_factory {
public:
    command_factory(const command_factory&) = delete;
    command_factory& operator=(const command_factory&) = delete;

    static command_factory& get_instance();

    template<typename command_type>
    void add_command(const std::string& command_name) {
        std::cout << "Added command: " << command_name << std::endl;
        command_map[command_name] = [](const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
            return std::make_shared<command_type>(options);
        };
    }

    void set_data(const std::string& command_name, const std::unordered_map<std::string, 
    std::vector<std::variant<int, double, std::string>>>& option_map);

    std::shared_ptr<command> create_command(); 
    void print_command_map() const;

private:
    command_factory() = default;
    std::string current_command;
    std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>> options;

    std::unordered_map<std::string, std::function<std::shared_ptr<command>(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>&)>> command_map;
};
