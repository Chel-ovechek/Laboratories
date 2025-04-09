#pragma once
#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    // �����������
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}
    // ����������
    ~Character();

    void displayInfo() const;
};


