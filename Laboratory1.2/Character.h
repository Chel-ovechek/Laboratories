#pragma once
#include <string>
#include <iostream>

class Character {
public:
    std::string name;
    int health;
    int attackPower;

    Character(const std::string& n, int hp, int ap)
        : name(n), health(hp), attackPower(ap) {}

    void displayInfo() const {
        std::cout << name << " HP: " << health << std::endl;
    }
};

