#pragma once

#include "shape_command.hpp"

class create_square_shape : public shape_command {
public:
    create_square_shape(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& shape_options) {
        const auto& color_options = shape_options.at("-color");
        shape_color = std::get<std::string>(color_options[0]);

        const auto& size_options = shape_options.at("-size");
        shape_side_length = std::get<int>(size_options[0]);

        const auto& position_options = shape_options.at("-pos");
        position_x = std::get<int>(position_options[0]);
        position_y = std::get<int>(position_options[1]);
    }

    void run() override {
        std::cout << "Running create_square_shape command." << std::endl;
        std::cout << "Color: " << shape_color << ", Side Length: " << shape_side_length 
                  << ", Position: (" << position_x << ", " << position_y << ")" << std::endl;
    }

private:
    std::string shape_color;
    int shape_side_length;
    int position_x;
    int position_y;
};
