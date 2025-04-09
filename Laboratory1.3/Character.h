#pragma once
#include "Entity.h"
class Character : public Entity {
public:
    Character(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {}

    // Переопределение метода attack
    void toAttack(Entity& target) override;

    void heal(int amount) override;

    // Переопределение метода displayInfo
    void displayInfo() const override;
};


