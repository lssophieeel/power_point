#pragma once

#include "item.hpp"

class circle_shape : public item {
public:
    circle_shape(int radius);

    void set_position(const position& pos) override;
    void set_color(const color& c) override;
    void set_index(std::size_t index) override;
    void set_size(const size& shape_size) override;

    position get_position() const override;
    color get_color() const override;
    std::size_t get_index() const override;
    size get_size() const override;
};
