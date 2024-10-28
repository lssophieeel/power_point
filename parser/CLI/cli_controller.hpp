#pragma once

#include "./parser/tokenizer.hpp"
#include "./parser/parser.hpp"
#include "./command_creator/command_factory.hpp"

#include <iostream>

class cli_controller {
public:
    cli_controller() = default;
    void start_cli();

private:
};
