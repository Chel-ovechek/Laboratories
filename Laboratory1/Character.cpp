#include "Character.h"

Character::Character(const std::string& n, int h, int a, int d)
    : name(n), max_health(h), attack(a), defense(d) {
    curent_health = max_health;
}

void Character::attackEnemy(Character& enemy) {
    int damage = attack - enemy.defense;
    if (damage > 0) {
        enemy.curent_health -= damage;
        std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
    }
    else {
        std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
    }
}

void Character::heal(int amount) {
    curent_health += amount;
    if (curent_health > max_health) {
        curent_health = max_health;
    }
    std::cout << "heal " << name << " for " << amount << std::endl;
}

void Character::takeDamage(int amount) {
    curent_health -= amount;
    if (curent_health < 0) {
        curent_health = 0;
    }
    std::cout << "takeDamage " << name << " for " << amount << std::endl;
}


