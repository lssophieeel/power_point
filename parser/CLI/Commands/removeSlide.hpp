#pragma once

#include "command.hpp"

class remove_slide : public command {
public:
    remove_slide(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& indexOptions = options.at("-index");
        index = std::get<int>(indexOptions[0]);
    }

    void execute() override {
        std::cout << "Executing remove_slide command." << std::endl;
        std::cout << "Index: " << index << std::endl;
    }

private:
    int index;
};
