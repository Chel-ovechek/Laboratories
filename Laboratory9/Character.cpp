#include "Character.h"
#include <iostream>

Character::Character(const std::string& n, int h, int a, int d)
    : name(n), health(h), attack(a), defense(d), level(1), experience(0) {}

void Character::attackEnemy(Character& enemy) {
    int damage = attack - enemy.getDefense();
    if (damage > 0) {
        enemy.setHealth(enemy.getHealth() - damage);
        std::cout << name << " attacks " << enemy.getName() << " for " << damage << " damage!" << std::endl;
    }
    else {
        std::cout << name << " attacks " << enemy.getName() << ", but it has no effect!" << std::endl;
    }
    if (enemy.getHealth() <= 0) {
        throw std::runtime_error(enemy.getName() + " has been defeated!");
    }
}

void Character::attackMonster(Monster& monster) {
    int damage = attack - monster.getDefense();
    if (damage > 0) {
        monster.setHealth(monster.getHealth() - damage);
        std::cout << name << " attacks " << monster.getName() << " for " << damage << " damage!" << std::endl;
    }
    else {
        std::cout << name << " attacks " << monster.getName() << ", but it has no effect!" << std::endl;
    }
    if (monster.getHealth() <= 0) {
        throw std::runtime_error(monster.getName() + " has been defeated!");
    }
}

void Character::heal(int amount) {
    health += amount;
    if (health > 100) health = 100;
    std::cout << name << " heals for " << amount << " HP!" << std::endl;
}

void Character::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        level++;
        experience -= 100;
        std::cout << name << " leveled up to level " << level << "!" << std::endl;
    }
}

void Character::displayInfo() const {
    std::cout << "Name: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense
        << ", Level: " << level << ", Experience: " << experience << std::endl;
}

std::string Character::getName() const { return name; }
int Character::getHealth() const { return health; }
void Character::setHealth(int h) { health = h; }
int Character::getAttack() const { return attack; }
int Character::getDefense() const { return defense; }
int Character::getLevel() const { return level; }
int Character::getExperience() const { return experience; }