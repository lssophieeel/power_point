#pragma once

#include <exception>
#include <vector>

#include "tokenizer.hpp"
#include "../Command_Creator/command_list.hpp"

enum class states {
    START_STATE, END_STATE,
    WORD_STATE, OPTION_STATE, SHAPE_OPTION_STATE, VALUE_STATE
};

class syntax_analyzer {
public:
    syntax_analyzer() = default;
    bool analyze(const std::vector<Token>&);

private:
    static states current_state;
    static bool is_single_word;
};

class syntax_error_exception : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Syntax Error";
    }
};

class unknown_exception : public std::exception {
public:
    const char* what() const noexcept override {
        return "An unknown error occurred.";
    }
};
