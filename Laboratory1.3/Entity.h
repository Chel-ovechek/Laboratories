#pragma once
#include <iostream>
#include <string>

class Entity {
protected:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Entity(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    // Виртуальный метод для атаки
    virtual void toAttack(Entity& target);

    // Виртуальный метод для вывода информации
    virtual void displayInfo() const;

    virtual void heal(int amount) {}

    // Виртуальный деструктор
    virtual ~Entity() {}



    // Геттеры
    int getHealth() const { return health; }
    int getDefense() const { return defense; }
    std::string getName() const { return name; }

    void takeDamage(int damage) { health -= damage; }
};

