#include "Player.h"

void Player::displayInfo() const {
    Entity::displayInfo(); // Вызов метода базового класса
    std::cout << "Experience: " << experience << std::endl;
}