#pragma once

#include <string>
#include <variant>

struct position {
    int x = 0;
    int y = 0;
};

struct color {
    std::string value;
};

using size_variant = std::variant<int, std::pair<int, int>>;

class drawable_item {
public:
    virtual ~drawable_item() = default;

    virtual void set_position(const position&) = 0;
    virtual void set_color(const color&) = 0;
    virtual void set_index(std::size_t) = 0;
    virtual void set_size(const size_variant&) = 0;

    virtual position get_position() const = 0;
    virtual color get_color() const = 0;
    virtual std::size_t get_index() const = 0;
    virtual size_variant get_size() const = 0;

protected:
    position item_position;
    color item_color;
    std::size_t item_index = 0;
    size_variant item_size;
};
