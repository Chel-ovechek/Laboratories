#include "Entity.h"

void Entity::toAttack(Entity& target) {
    int damage = attack - target.defense;
    if (damage > 0) {
        target.health -= damage;
        std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
    }
    else {
        std::cout << name << " attacks " << target.name << ", but it has no effect!\n";
    }
}

void Entity::displayInfo() const {
    std::cout << "Name: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense << std::endl;
}