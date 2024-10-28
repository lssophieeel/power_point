#pragma once

#include "command.hpp"

class play : public command {
public:
    play(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& data) {
       
    }
    void execute() override {
        std::cout << "Executing play command." << std::endl;
    }
};
