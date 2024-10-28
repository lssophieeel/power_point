#include "cli_controller.hpp"

void controller::cli_controller() {
    while (true) {
        std::string command;
        while (true) {
            std::getline(std::cin, command);
            parser::get_instance().parse(command);
            std::shared_ptr<command> cmd = command_factory::get_instance().create_command();            
        }
    }
}
