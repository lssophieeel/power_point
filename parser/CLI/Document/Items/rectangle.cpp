#include "rectangle.hpp"

rectangle::rectangle(int width, int height) {
    size = std::make_pair(width, height);
}

void rectangle::set_pos(const position& pos) {
    position = pos;
}

void rectangle::set_color(const color& c) {
    color = c;
}

void rectangle::set_index(std::size_t i) {
    index = i;
}

void rectangle::set_size(const size& s) {
    size = s;
}

position rectangle::get_pos() const {
    return position;
}

color rectangle::get_color() const {
    return color;
}

std::size_t rectangle::get_index() const {
    return index;
}

size rectangle::get_size() const {
    return size;
}
