#include "Game.h"
#include "Logger.h"
#include <iostream>

int main() {
    try {
        Logger<std::string> logger("game_log.txt");
        Game game("Hero");

        logger.log("Game started.");
        game.startGame();

        logger.log("Starting first fight.");
        game.fight();

        logger.log("Saving progress.");
        game.saveProgress("savegame.txt");

        logger.log("Loading progress.");
        game.loadProgress("savegame.txt");

        logger.log("Starting second fight.");
        game.fight();

    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}