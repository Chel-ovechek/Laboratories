#pragma once
#include <iostream>
#include <string>

class Weapon {
private:
    std::string title;
    int damage;
    int weight;

public:
    // Конструктор
    Weapon(const std::string& t, int d, int w)
        : title(t), damage(d), weight(w) {}

    // Деструктор
    ~Weapon();

    void displayInfo() const;
};

