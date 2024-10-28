#pragma once

#include "shape_command.hpp"

class create_text : public shape_command {
public:
    create_text(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& shape_options) {
        const auto& text_options = shape_options.at("-text");
        shape_text = std::get<std::string>(text_options[0]);

        const auto& size_options = shape_options.at("-size");
        font_size = std::get<int>(size_options[0]);

        const auto& position_options = shape_options.at("-pos");
        position_x = std::get<int>(position_options[0]);
        position_y = std::get<int>(position_options[1]);
    }

    void run() override {
        std::cout << "Running create_text command." << std::endl;
        std::cout << "Text: " << shape_text << ", Font Size: " << font_size 
                  << ", Position: (" << position_x << ", " << position_y << ")" << std::endl;
    }

private:
    std::string shape_text;
    int font_size;
    int position_x;
    int position_y;
};
