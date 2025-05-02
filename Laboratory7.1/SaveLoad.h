#pragma once
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "GameManager.h"
#include "Entity.h"
#include "Player.h"

// Объявление функций
inline void saveToFile(const GameManager<Entity*>& manager, const std::string& filename);
inline void loadFromFile(GameManager<Entity*>& manager, const std::string& filename);

// Реализация функций
inline void saveToFile(const GameManager<Entity*>& manager, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing");
    }
    for (const auto& entity : manager.entities) {
        file << "Player " << entity->serialize() << "\n";
    }
}

inline void loadFromFile(GameManager<Entity*>& manager, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for reading");
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        if (type == "Player") {
            std::string data;
            std::getline(iss, data);
            Player* p = new Player();
            p->deserialize(data);
            manager.addEntity(p);
        }
    }
}


