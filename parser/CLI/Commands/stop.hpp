#pragma once

#include "command.hpp"

class stop : public Command {
public:
    stop(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& params) { }
    void execute() override {
        std::cout << "Executing Stop command." << std::endl;
    }
};
