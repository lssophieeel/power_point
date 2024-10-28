#pragma once

#include "command.hpp"

class EditSlide : public Command {
public:
    EditSlide(const std::unordered_map<std::string, std::vector<std::variant<int, double, std::string>>>& options) {
        const auto& index_options = options.at("-index");
        index = std::get<int>(index_options[0]);

        const auto& color_options = options.at("-color");
        color = std::get<std::string>(color_options[0]);
    }

    void execute() override {
        std::cout << "Executing edit_slide command." << std::endl;
        std::cout << "Index: " << index << ", Color: " << color << std::endl;
    }

private:
    int index;
    std::string color;
};
