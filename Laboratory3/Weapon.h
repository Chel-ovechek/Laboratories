#pragma once
#include <string>
#include <iostream>

class Weapon {
private:
    std::string title;
    int damage;


public:
    Weapon(const std::string& t, int d)
        : title(t), damage(d) {}

    // Перегрузка оператора +
    Weapon operator+(const Weapon& other) {
        Weapon a("new_weapon", this->damage + other.damage);

        return a;
    }

    bool operator>(const Weapon& other) {
        return damage>other.damage;
    }

    // Перегрузка оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
        os << "Weapon: " << weapon.title << ", Damage: " << weapon.damage;
        return os;
    }
};

