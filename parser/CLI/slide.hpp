#pragma once

#include "item_collection.hpp"  

#include <string>

class slide {
public:
    slide(int i, const std::string& c);

    void set_color(const std::string& c);

    void add_item(std::shared_ptr<item> item); 
    void remove_item(std::size_t index);   
    std::shared_ptr<item> get_item(std::size_t index) const; 
    std::size_t item_count() const;  

private:
    std::string color;
    item_collection items; 
};
