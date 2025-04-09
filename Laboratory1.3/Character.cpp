#include "Character.h"

void Character::toAttack(Entity& target) {
    int damage = attack - target.getDefense();
    if (damage > 0) {
        // Шанс на критический удар (20%)
        if (rand() % 100 < 20) {
            damage *= 2;
            std::cout << "Critical hit! ";
        }
        target.takeDamage(damage);
        std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
    }
    else {
        std::cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
    }
}

void Character::heal(int amount) {
    health += amount;
    std::cout << name << "heals for " << amount << ". Current HP is " << health << std::endl;
}

void Character::displayInfo() const {
    std::cout << "Character: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense << std::endl;
}