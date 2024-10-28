#pragma once

#include "shape_command.hpp"

class create_slide : public shape_command {
public:
    create_slide(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& shape_options) {
        const auto& index_options = shape_options.at("-index");
        slide_index = std::get<int>(index_options[0]);
    }

    void run() override {
        std::cout << "Running create_slide command." << std::endl;
        std::cout << "Index: " << slide_index << std::endl;
    }

private:
    int slide_index;
};
