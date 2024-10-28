#include "slide.hpp"

slide::slide(int i, const std::string& c) : color(c) { }

void slide::set_color(const std::string& c) {
    color = c;
}

void slide::add_item(std::shared_ptr<item> item) {
    items.add_item(item);
}

void slide::remove_item(std::size_t index) {
    items.remove_item(index);
}

std::shared_ptr<item> slide::get_item(std::size_t index) const {
    return items.get_item(index);
}

std::size_t slide::item_count() const {
    return items.size();
}
