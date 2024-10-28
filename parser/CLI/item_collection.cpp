#include "item_collection.hpp"

void item_collection::add_item(std::shared_ptr<drawable_item> item) {
    items.push_back(item);
}

void item_collection::remove_item(std::size_t index) {
    if (index < items.size()) {
        items.erase(items.begin() + index);
    }
}

std::shared_ptr<drawable_item> item_collection::get_item(std::size_t index) const {
    if (index < items.size()) {
        return items[index];
    }
    return nullptr;
}

std::size_t item_collection::get_size() const {
    return items.size();
}
