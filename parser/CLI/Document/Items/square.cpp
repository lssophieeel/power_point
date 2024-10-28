#include "square.hpp"

square::square(int s) {
    size = s;
}

void square::set_pos(const Position& pos) {
    position = pos;
}

void square::set_color(const Color& c) {
    color = c;
}

void square::set_index(std::size_t i) {
    index = i;
}

void square::set_size(const Size& s) {
    size = s;
}

Position square::get_pos() const {
    return position;
}

Color square::get_color() const {
    return color;
}

std::size_t square::get_index() const {
    return index;
}

Size square::get_size() const {
    return size;
}
