// text.cpp
#include "text.hpp"

text::text(const std::string& t) : text(t) { }

void text::set_pos(const position& pos) {
    position = pos;
}

void text::set_color(const color& c) {
    color = c;
}

void text::set_index(std::size_t i) {
    index = i;
}

void text::set_size(const size& s) {
    size = s;
}

position text::get_pos() const {
    return position;
}

color text::get_color() const {
    return color;
}

std::size_t text::get_index() const {
    return index;
}

size text::get_size() const {
    return size;
}

void text::set_content(const std::string& t) {
    text = t;
}

std::string text::get_content() const {
    return text;
}
