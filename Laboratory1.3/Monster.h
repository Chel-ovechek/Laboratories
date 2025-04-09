#pragma once
#include "Entity.h"
class Monster : public Entity {
public:
    Monster(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {}

    // ��������������� ������ attack
    virtual void toAttack(Entity& target) override;

    // ��������������� ������ displayInfo
    void displayInfo() const override;
};


