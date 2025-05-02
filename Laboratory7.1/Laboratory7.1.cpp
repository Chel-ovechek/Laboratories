#include <iostream>
#include "GameManager.h"
#include "Player.h"
#include "SaveLoad.h"

int main() {
    try {
        GameManager<Entity*> manager;

        // Создаем персонажей
        manager.addEntity(new Player("Hero", 100, 5));
        manager.addEntity(new Player("Villain", 80, 3));

        // Сохраняем в файл
        saveToFile(manager, "game_save.txt");

        // Создаем новый менеджер и загружаем из файла
        GameManager<Entity*> loadedManager;
        loadFromFile(loadedManager, "game_save.txt");
        loadedManager.displayAll();

        // Освободить память
        for (auto entity : loadedManager.entities) {
            delete entity;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}