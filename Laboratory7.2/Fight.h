#pragma once
#include <thread>
#include <mutex>
#include "Character.h"
#include "Monster.h"

extern std::mutex combatMutex; // объ€вление внешнего мьютекса

// —делать функцию inline
inline void fight(Character& hero, Monster& monster) {
    while (hero.health > 0 && monster.health > 0) {
        {
            std::lock_guard<std::mutex> lock(combatMutex);
            // јтака геро€
            monster.health -= hero.attackPower;
            std::cout << hero.name << " атакует " << monster.name
                << ", его HP теперь " << monster.health << std::endl;

            if (monster.health <= 0) {
                std::cout << monster.name << " повержен!\n";
                break;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        {
            std::lock_guard<std::mutex> lock(combatMutex);
            // јтака монстра
            hero.health -= monster.attackPower;
            std::cout << monster.name << " атакует " << hero.name
                << ", его HP теперь " << hero.health << std::endl;

            if (hero.health <= 0) {
                std::cout << hero.name << " погиб!\n";
                break;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
