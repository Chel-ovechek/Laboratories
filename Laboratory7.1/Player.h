#pragma once
#include "Entity.h"
#include <string>
#include <sstream>
#include <iostream>

class Player : public Entity {
private:
    std::string name;
    int health;
    int level;

public:
    Player(const std::string& n = "", int h = 100, int l = 1)
        : name(n), health(h), level(l) {}

    void displayInfo() const override {
        std::cout << "Player: " << name << ", HP: " << health << ", Level: " << level << std::endl;
    }

    std::string serialize() const override {
        return name + " " + std::to_string(health) + " " + std::to_string(level);
    }

    void deserialize(const std::string& data) override {
        std::istringstream iss(data);
        iss >> name >> health >> level;
    }
};
