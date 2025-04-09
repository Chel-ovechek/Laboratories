#pragma once
#include <iostream>
#include <string>

class Monster {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    // �����������
    Monster(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    // ����������
    ~Monster();

    void displayInfo() const;
};


