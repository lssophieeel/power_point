#pragma once

#include "item.hpp"

class square : public Item {
public:
    square(int s);

    void set_pos(const Position& pos) override;
    void set_color(const Color& c) override;
    void set_index(std::size_t i) override;
    void set_size(const Size& s) override;

    Position get_pos() const override;
    Color get_color() const override;
    std::size_t get_index() const override;
    Size get_size() const override;
};
