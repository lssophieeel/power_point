#pragma once

#include "item.hpp"

class rectangle : public item {
public:
    rectangle(int width, int height);

    void set_pos(const position& pos) override;
    void set_color(const color& c) override;
    void set_index(std::size_t i) override;
    void set_size(const size& s) override;

    position get_pos() const override;
    color get_color() const override;
    std::size_t get_index() const override;
    size get_size() const override;
};
