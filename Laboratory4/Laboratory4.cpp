#include <iostream>
#include "Inventory.h"
#include <memory>
#include <string>

int main() {
    //// Массив умных указателей на базовый класс
    //std::unique_ptr<Entity> entities[] = {
    //    std::make_unique<Player>("Hero", 100, 0),
    //    std::make_unique<Enemy>("Goblin", 50, "Goblin")
    //};

    //// Полиморфизм и автоматическое управление памятью
    //for (const auto& entity : entities) {
    //    entity->displayInfo();
    //}

    std::unique_ptr<Inventory> inventory(new Inventory());

    inventory->addItem("knife");
    inventory->addItem("sword");
    inventory->addItem("poison");
    
    inventory->displayInventory();

    return 0;
}

