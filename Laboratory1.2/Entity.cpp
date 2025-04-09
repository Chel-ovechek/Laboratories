#include "Entity.h"

void Entity::displayInfo() const {
    std::cout << "Name: " << name << ", HP: " << health << std::endl;
}