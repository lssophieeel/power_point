#pragma once

#include "items/item.hpp"  

#include <vector>
#include <memory>

class item_collection {
public:
    void add_item(std::shared_ptr<drawable_item> item);
    void remove_item(std::size_t index);
    std::shared_ptr<drawable_item> get_item(std::size_t index) const;
    std::size_t get_size() const;

private:
    std::vector<std::shared_ptr<drawable_item>> items;  
};
