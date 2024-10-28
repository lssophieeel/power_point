#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
#include <iostream>

class command {
public:
    virtual void execute() = 0;
    virtual ~command() = default;
};
