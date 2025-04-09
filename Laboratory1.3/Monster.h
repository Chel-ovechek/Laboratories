#pragma once
#include "Entity.h"
class Monster : public Entity {
public:
    Monster(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {}

    // Переопределение метода attack
    virtual void toAttack(Entity& target) override;

    // Переопределение метода displayInfo
    void displayInfo() const override;
};


