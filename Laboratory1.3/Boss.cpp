#include "Boss.h"

void Boss::toAttack(Entity& target) {
    // Шанс на быструю атаку (40%)
    if (rand() % 100 < 40) {
        for (int i = 1; i <= 3; i++) {
            int fast_damage = (rand() % (attack + 1) + attack*0.5) - target.getDefense(); // Быстрая атака от 50% до 150% от обычной атаки

            if (fast_damage > 0) {

                target.takeDamage(fast_damage);
                std::cout << name << " attacks " << target.getName() << " for " << fast_damage << " fast_damage!\n";
            }
            else {
                std::cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
            }
        }
    }
    else {
        int damage = attack - target.getDefense();
        if (damage > 0) {

            target.takeDamage(damage);
            std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
        }
    }
}

void Boss::displayInfo() const {
    std::cout << "Boss: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense << std::endl;
}
