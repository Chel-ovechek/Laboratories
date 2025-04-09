#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "Boss.h"

int main() {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    // Создание объектов
    Character hero("Hero", 100, 20, 10);
    Monster goblin("Goblin", 50, 15, 5);
    Monster dragon("Dragon", 150, 25, 20);
    Boss boss("Dark_guardian", 200, 30, 15);

    // Массив указателей на базовый класс
    Entity* entities[] = { &hero, &goblin, &dragon, &boss};

    // Полиморфное поведение
    for (auto& entity : entities) {
        entity->displayInfo(); // Вывод информации о сущности
    }

    // Бой между персонажем и монстрами
    hero.toAttack(goblin);
    goblin.toAttack(hero);
    dragon.toAttack(hero);
    hero.heal(15);
    boss.toAttack(hero);

    return 0;
}


