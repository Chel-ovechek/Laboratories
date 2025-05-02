#pragma once
#include <string>
#include <iostream>

class Monster {
public:
    std::string name;
    int health;
    int attackPower;

    Monster(const std::string& n, int hp, int ap)
        : name(n), health(hp), attackPower(ap) {}

    void displayInfo() const {
        std::cout << name << " HP: " << health << std::endl;
    }
};

