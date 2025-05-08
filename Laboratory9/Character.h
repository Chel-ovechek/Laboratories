#pragma once
#include <string>
#include "Monster.h" // Для доступа к классу Monster

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;
    int level;
    int experience;

public:
    Character(const std::string& n, int h, int a, int d);

    void attackEnemy(Character& enemy);
    void attackMonster(Monster& monster); // Новый метод для атаки монстров
    void heal(int amount);
    void gainExperience(int exp);
    void displayInfo() const;

    std::string getName() const;
    int getHealth() const;
    void setHealth(int h);
    int getAttack() const;
    int getDefense() const;
    int getLevel() const;
    int getExperience() const;
};