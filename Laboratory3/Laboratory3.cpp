#include <iostream>
#include "Character.h"
#include "Weapon.h"

int main() {
    Character hero1("Hero", 100, 20, 10);
    Character hero2("Hero", 100, 20, 10);
    Character hero3("Warrior", 150, 25, 15);

    if (hero1 == hero2) {
        std::cout << "Hero1 and Hero2 are the same!\n";
    }
    if (!(hero1 == hero3)) {
        std::cout << "Hero1 and Hero3 are different!\n";
    }

    std::cout << hero1 << std::endl; // Вывод информации о персонаже

    Weapon weapon1("gun", 100);
    Weapon weapon2("turbogun", 100);
    Weapon weapon3("gun", 150);

    if (weapon3 > weapon2) {
        std::cout << "Weapon3 more power than weapon2!\n";
    }

    Weapon firegun = weapon1 + weapon2;

    std::cout << firegun << std::endl; // Вывод информации о персонаже
    return 0;
}
