#include <iostream>
#include "Character.h"

int main()
{
    Character hero("Hero", 100, 20, 10);
    Character monster("Goblin", 50, 15, 5);

    // Выводим информацию о персонажах
    hero.displayInfo();
    monster.displayInfo();

    // Герой атакует монстра
    hero.attackEnemy(monster);
    monster.displayInfo();

    monster.heal(5);
    monster.displayInfo();

    hero.takeDamage(28);
    hero.displayInfo();
}
