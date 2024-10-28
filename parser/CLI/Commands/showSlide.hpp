#pragma once

#include "command.hpp"

class show_slide : public command {
public:
    show_slide(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& index_options = options.at("-index");
        index = std::get<int>(index_options[0]);
    }

    void execute() override {
        std::cout << "Executing ShowSlide command." << std::endl;
        std::cout << "Index: " << index << std::endl;
    }

private:
    int index;
};
