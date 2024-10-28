#pragma once

#include "shape_command.hpp"

class create_circle_shape : public shape_command {
public:
    create_circle_shape(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& shape_options) {
        const auto& color_options = shape_options.at("-color");
        shape_color = std::get<std::string>(color_options[0]);

        const auto& size_options = shape_options.at("-size");
        shape_radius = std::get<int>(size_options[0]);

        const auto& position_options = shape_options.at("-pos");
        position_x = std::get<int>(position_options[0]);
        position_y = std::get<int>(position_options[1]);
    }

    void run() override {
        std::cout << "Running create_circle_shape command." << std::endl;
        std::cout << "Color: " << shape_color << ", Radius: " << shape_radius 
                  << ", Position: (" << position_x << ", " << position_y << ")" << std::endl;
    }

private:
    std::string shape_color;
    int shape_radius;
    int position_x;
    int position_y;
};
