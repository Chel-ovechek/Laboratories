#include "Monster.h"
#include "Character.h"
#include <iostream>

Monster::Monster(const std::string& n, int h, int a, int d)
    : name(n), health(h), attack(a), defense(d) {}

void Monster::attackEnemy(Character& enemy) {
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

void Monster::displayInfo() const {
    std::cout << "Monster: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense << std::endl;
}

std::string Monster::getName() const { return name; }
int Monster::getHealth() const { return health; }
void Monster::setHealth(int h) { health = h; }
int Monster::getAttack() const { return attack; }
int Monster::getDefense() const { return defense; }

// Goblin
Goblin::Goblin(const std::string& n) : Monster(n, 50, 15, 5) {}
void Goblin::attackEnemy(Character& enemy) {
    std::cout << name << " uses a sneaky attack!" << std::endl;
    Monster::attackEnemy(enemy);
}

// Dragon
Dragon::Dragon(const std::string& n) : Monster(n, 150, 30, 20) {}
void Dragon::attackEnemy(Character& enemy) {
    std::cout << name << " breathes fire!" << std::endl;
    Monster::attackEnemy(enemy);
}

// Skeleton
Skeleton::Skeleton(const std::string& n) : Monster(n, 70, 20, 10) {}
void Skeleton::attackEnemy(Character& enemy) {
    std::cout << name << " rattles its bones and strikes!" << std::endl;
    Monster::attackEnemy(enemy);
}