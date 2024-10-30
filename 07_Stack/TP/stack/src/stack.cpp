#include "stack.h"
#include <iostream>

Stack::Stack() {}

void Stack::push(const std::string& item) {
    items.push_back(item);
}

std::string Stack::pop() {
    if (!items.empty()) {
        std::string item = items.back();
        items.pop_back();
        return item;
    }
    return ""; // Return empty string if stack is empty
}

bool Stack::isEmpty() const {
    return items.empty();
}

void Stack::display() const {
    for (auto it = items.rbegin(); it != items.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}
