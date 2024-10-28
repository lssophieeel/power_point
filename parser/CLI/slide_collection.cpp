#include "slide_collection.hpp"

void slide_collection::add_slide(std::shared_ptr<slide> slide) {
    slides.push_back(slide);
}

void slide_collection::remove_slide(std::size_t index) {
    if (index < slides.size()) {
        slides.erase(slides.begin() + index);
    }
}

std::shared_ptr<slide> slide_collection::get_slide(std::size_t index) const {
    if (index < slides.size()) {
        return slides[index];
    }
    return nullptr;
}

std::size_t slide_collection::size() const {
    return slides.size();
}
