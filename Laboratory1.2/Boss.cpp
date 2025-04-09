#include "Boss.h"

void Boss::specialAbility() const {
    std::cout << "Kill all entity in range 10 meters: "<< std::endl;
}

void Boss::displayInfo() const {
    Enemy::displayInfo(); // Вызов метода базового класса
    std::cout << "SpecialAbility: ";
    specialAbility();
}