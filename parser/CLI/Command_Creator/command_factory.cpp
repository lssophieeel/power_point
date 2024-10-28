#include "command_factory.hpp"

command_factory& command_factory::get_instance() {
    static command_factory instance;
    return instance;
}

void command_factory::set_data(const std::string& command_name, const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& option_map) {
    current_command = command_name;
    options = option_map;
}

std::shared_ptr<command> command_factory::create_command() {
    std::cout << "Looking for command: " << current_command;
    print_command_map();
    auto it = command_map.find(current_command);
    if (it != command_map.end()) {
        return it->second(options); 
    } else {
        std::cerr << "Command factory unknown command: " << current_command << std::endl;
        return nullptr;
    }
}

void command_factory::print_command_map() const {
    std::cout << "Added commands:" << std::endl;
    for (const auto& [command_name, func] : command_map) {
        std::cout << " - Command: " << command_name 
                  << ", Function type: " << typeid(func).name() << std::endl;
    }
}
