#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

int main() {
    // Создаем объекты игрока и врага
    Player hero("Hero", 100, 0);
    Enemy monster("Goblin", 50, "Goblin");
    Boss boss("Haggard", 90, "Naga");

    // Выводим информацию о персонажах
    hero.displayInfo();
    monster.displayInfo();
    boss.displayInfo();

    return 0;
}
