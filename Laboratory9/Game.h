#pragma once
#include "Character.h"
#include "Monster.h"
#include "Inventory.h"
#include <memory>

class Game {
private:
    Character player;
    Inventory inventory;
    std::unique_ptr<Monster> currentMonster;

public:
    Game(const std::string& playerName);
    void startGame();
    void fight();
    void saveProgress(const std::string& filename) const;
    void loadProgress(const std::string& filename);
};
