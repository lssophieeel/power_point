#pragma once

#include "shape_command.hpp"

class create_rectangle_shape : public shape_command {
public:
    create_rectangle_shape(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& shape_options) {
        std::cout << "Created create_rectangle_shape command" << std::endl;

        const auto& color_options = shape_options.at("-color");
        shape_color = std::get<std::string>(color_options[0]); 

        const auto& size_options = shape_options.at("-size");
        shape_width = std::get<int>(size_options[0]);   
        shape_height = std::get<int>(size_options[1]);  

        const auto& position_options = shape_options.at("-pos");
        position_x = std::get<int>(position_options[0]); 
        position_y = std::get<int>(position_options[1]); 
    }

    void run() override {
        std::cout << "Running create_rectangle_shape command." << std::endl;
        std::cout << "Color: " << shape_color << ", Width: " << shape_width << ", Height: " << shape_height 
                  << ", Position: (" << position_x << ", " << position_y << ")" << std::endl;
    }

private:
    std::string shape_color;
    int shape_width = 0;  
    int shape_height = 0;  
    int position_x = 0;      
    int position_y = 0;       
};
