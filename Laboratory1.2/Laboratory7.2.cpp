#include <iostream>
#include <thread>
#include "Character.h"
#include "Monster.h"
#include "Fight.h"

std::mutex combatMutex; // определяем глобальный мьютекс

int main() {
    setlocale(LC_ALL, "");
    Character hero("Hero", 100, 15);
    Monster goblin("Goblin", 50, 10);

    std::thread battleThread(fight, std::ref(hero), std::ref(goblin));
    battleThread.join(); // дождаться завершения боя

    std::cout << "Бой завершен!\n";
    hero.displayInfo();

    return 0;
}