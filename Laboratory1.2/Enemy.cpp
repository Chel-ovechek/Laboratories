#include "Enemy.h"

void Enemy::displayInfo() const {
    Entity::displayInfo(); // Вызов метода базового класса
    std::cout << "Type: " << type << std::endl;
}