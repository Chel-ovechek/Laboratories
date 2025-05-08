#include "Game.h"
#include <fstream>
#include <iostream>

Game::Game(const std::string& playerName) : player(playerName, 100, 20, 10) {
    currentMonster = std::make_unique<Goblin>("Goblin");
}

void Game::startGame() {
    std::cout << "Welcome to the RPG Game!" << std::endl;
    player.displayInfo();
    inventory.addItem("Sword");
    inventory.addItem("Health Potion");
    inventory.displayInventory();
}

void Game::fight() {
    std::cout << "\nA " << currentMonster->getName() << " appears!" << std::endl;
    currentMonster->displayInfo();

    try {
        player.attackMonster(*currentMonster); // Используем attackMonster для Monster
        if (currentMonster->getHealth() > 0) {
            currentMonster->attackEnemy(player); // Монстр атакует персонажа
        }
        player.gainExperience(50);
        player.displayInfo();
        currentMonster->displayInfo();
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        player.gainExperience(100);
        currentMonster = std::make_unique<Dragon>("Dragon");
    }
}

void Game::saveProgress(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for saving: " + filename);
    }
    file << player.getName() << "\n"
        << player.getHealth() << "\n"
        << player.getAttack() << "\n"
        << player.getDefense() << "\n"
        << player.getLevel() << "\n"
        << player.getExperience();
    file.close();
    std::cout << "Progress saved to " << filename << std::endl;
}

void Game::loadProgress(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for loading: " + filename);
    }
    std::string name;
    int health, attack, defense, level, experience;
    std::getline(file, name);
    file >> health >> attack >> defense >> level >> experience;
    file.close();

    player = Character(name, health, attack, defense);
    player.setHealth(health);
    player.gainExperience(experience);
    std::cout << "Progress loaded from " << filename << std::endl;
    player.displayInfo();
}