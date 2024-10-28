#include "circle.hpp"

class circle_shape {
public:
    circle_shape(int radius) {
        shape_size = radius;
    }

    void set_position(const position& pos) {
        shape_position = pos;
    }

    void set_color(const color& c) {
        shape_color = c;
    }

    void set_index(std::size_t i) {
        shape_index = i;
    }

    void set_size(const size& s) {
        shape_size = s;
    }

    position get_position() const {
        return shape_position;
    }

    color get_color() const {
        return shape_color;
    }

    std::size_t get_index() const {
        return shape_index;
    }

    size get_size() const {
        return shape_size;
    }

private:
    position shape_position;
    color shape_color;
    std::size_t shape_index;
    size shape_size;
};
