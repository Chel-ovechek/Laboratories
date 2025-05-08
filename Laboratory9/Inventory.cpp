#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const std::string& item) {
    items.push_back(item);
    std::cout << "Added " << item << " to inventory." << std::endl;
}

void Inventory::removeItem(const std::string& item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            items.erase(it);
            std::cout << "Removed " << item << " from inventory." << std::endl;
            return;
        }
    }
    std::cout << item << " not found in inventory." << std::endl;
}

void Inventory::displayInventory() const {
    if (items.empty()) {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }
    std::cout << "Inventory: ";
    for (const auto& item : items) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}