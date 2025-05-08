#pragma once
#include <thread>
#include <mutex>
#include "Character.h"
#include "Monster.h"

extern std::mutex combatMutex; // ���������� �������� ��������

// ������� ������� inline
inline void fight(Character& hero, Monster& monster) {
    while (hero.health > 0 && monster.health > 0) {
        {
            std::lock_guard<std::mutex> lock(combatMutex);
            // ����� �����
            monster.health -= hero.attackPower;
            std::cout << hero.name << " ������� " << monster.name
                << ", ��� HP ������ " << monster.health << std::endl;

            if (monster.health <= 0) {
                std::cout << monster.name << " ��������!\n";
                break;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        {
            std::lock_guard<std::mutex> lock(combatMutex);
            // ����� �������
            hero.health -= monster.attackPower;
            std::cout << monster.name << " ������� " << hero.name
                << ", ��� HP ������ " << hero.health << std::endl;

            if (hero.health <= 0) {
                std::cout << hero.name << " �����!\n";
                break;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
