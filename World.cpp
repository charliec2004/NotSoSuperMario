// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#include "World.h"
#include "Util.h"
#include <iostream>
#include <cstdlib>

// Constructor: Initialize the world with the given values
World::World(int levels, int dimension, int lives, int perCoins, int perEmpty, int perGoombas, int perKoopas, int perMushrooms)
    : numberOfLevels(levels), gridDimension(dimension), initialLives(lives),
      percentageCoins(perCoins), percentageEmpty(perEmpty), percentageGoombas(perGoombas),
      percentageKoopas(perKoopas), percentageMushrooms(perMushrooms), mario(nullptr), currentLevel(0) {}

// Destructor: Cleanup
World::~World() {
    if (mario) {
        delete mario;
    }
}

// Initialize the world
void World::initialize() {
    setupLevels();
    // its a mi a mario
    mario = new Mario(initialLives, 0, 0, 0);  // Initialize Mario with starting values
    mario->setPosition(rand() % gridDimension, rand() % gridDimension);  // Place Mario at random position in first level
}

// Setup the levels of the world
void World::setupLevels() {
    for (int i = 0; i < numberOfLevels; ++i) {
        levels[i].initialize(gridDimension);
        levels[i].populate(percentageCoins, 100 - (percentageCoins + percentageGoombas + percentageKoopas + percentageMushrooms), percentageGoombas, percentageKoopas, percentageMushrooms);
        if (i < numberOfLevels - 1) {  // No warp pipe in the final level
            levels[i].placeWarpPipe();
        }
        levels[i].placeBoss();  // Place boss in every level
    }
}

//  Move mario in a random direction
void World::moveMario(Logger &logger) {
    Util util; // instance of util
    Direction dir = util.getRandomDirection(); // dir is the random direction that is chosen by the generator
    // get marios position
    int row = mario->getRow();
    int col = mario->getCol();

    switch (dir) { // depending on what direction is chose, mario moves accordingly
        case UP:
            row = (row - 1 + gridDimension) % gridDimension;  // Move up and wrap around
            break;
        case DOWN:
            row = (row + 1) % gridDimension;  // Move down and wrap around
            break;
        case LEFT:
            col = (col - 1 + gridDimension) % gridDimension;  // Move left and wrap around
            break;
        case RIGHT:
            col = (col + 1) % gridDimension;  // Move right and wrap around
            break;
    }
    // apply to new position to mario and log it!
    mario->setPosition(row, col);
    logger.log("Mario moved to position (" + std::to_string(row) + "," + std::to_string(col) + ")");
}

// Handle the interaction of mario with the item at his current position
void World::handleInteraction(Logger &logger) { // passing into a reference to logger so that the function uses the actual logger
    // get marios position
    int row = mario->getRow(); 
    int col = mario->getCol();
    // item is equal to the character at marios current position in the current level
    char item = levels[currentLevel].getItemAt(row, col);

    switch (item) {
        // if mario interacts with a coin
        case 'c':
            mario->collectCoin();
            levels[currentLevel].setItemAt(row, col, 'x');  // Remove the coin
            logger.log("Mario collected a coin.");
            break;
        case 'm':
            mario->eatMushroom();
            levels[currentLevel].setItemAt(row, col, 'x');  // Remove the mushroom
            logger.log("Mario ate a mushroom.");
            break;
        case 'g':
        case 'k':
            if (mario->encounterEnemy(item)) {
                levels[currentLevel].setItemAt(row, col, 'x');  // Remove the enemy if defeated
                logger.log("Mario fought and defeated an enemy.");
            } else {
                if (mario->getPowerLevel() > 1) {
                    mario->decreasePowerLevel(1);
                    logger.log("Mario fought an enemy and lost. Power level decreased by 1.");
                } else {
                    mario->loseLife();
                    logger.log("Mario fought an enemy and lost a life.");
                    
                    if (mario->getLives() <= 0) {
                        logger.log("Mario has no lives left. Game over.");
                    }
                }
            }
            break;
        case 'b':
            while (true) {
                if (mario->encounterEnemy(item)) {
                    if (currentLevel == numberOfLevels - 1) {
                        logger.log("Mario defeated the final boss and saved the princess! Game won!");
                        mario->setLives(0);  // End the game
                        break;
                    } else {
                        logger.log("Mario defeated the level boss. Moving to next level.");
                        currentLevel++;  // Move to the next level
                        mario->setPosition(rand() % gridDimension, rand() % gridDimension);  // Place Mario at random position
                        break;
                    }
                } else { // if he loses
                    if (mario->getPowerLevel() > 1) {
                        mario->decreasePowerLevel(2);
                        logger.log("Mario fought the boss and lost. Power level decreased by 2.");
                    } else {
                        mario->loseLife();
                        logger.log("Mario fought the boss and lost a life.");
                        if (mario->getLives() > 0) {
                            mario->setPowerLevel(0);
                            logger.log("Mario continues with 0 power level.");
                            continue; // Continue fighting the boss
                        } else if (mario->getLives() <= 0){
                            logger.log("Mario has no lives left. Game over.");
                            break;
                        }
                    }
                }
            }
            break;
        case 'w':
            logger.log("Mario found a warp pipe and moved to the next level.");
            currentLevel++;
            mario->setPosition(rand() % gridDimension, rand() % gridDimension);  // Place Mario at random position
            break;
        case 'x':
        default:
            logger.log("Mario moved to an empty space.");
            break;
    }
}

// Update the game state
bool World::updateGameState(Logger &logger) {
    handleInteraction(logger);  // Handle current interaction
    if (mario->getLives() <= 0 || currentLevel >= numberOfLevels) {
        return false;  // Game over
    }
    moveMario(logger);  // Move Mario after the interaction
    return true;  // Continue game
}

// Log the current state of the world
void World::logState(Logger &logger) {
    logger.log("==========");
    logger.log("Level: " + std::to_string(currentLevel));
    logger.log("Mario is starting in position: (" + std::to_string(mario->getRow()) + "," + std::to_string(mario->getCol()) + ")");
    logger.log("==========");
    printLevelStateWithoutMario(logger);
    logger.log("==========");
}

// Print the current state of the world
void World::printWorldState(Logger &logger) const {
    logger.log("==========");
    logger.log("Current Level: " + std::to_string(currentLevel)); // logs current level
    logger.log("Mario's Position: (" + std::to_string(mario->getRow()) + "," + std::to_string(mario->getCol()) + ")"); // logs position
    logger.log("Mario's Power Level: " + std::to_string(mario->getPowerLevel())); // logs power level
    logger.log("Mario's Lives: " + std::to_string(mario->getLives())); // logs lives
    logger.log("Mario's Coins: " + std::to_string(mario->getCoins())); // logs coins 
    logger.log("==========");
    levels[currentLevel].printLevelState(logger, mario->getRow(), mario->getCol());
    logger.log("==========");
}

// Print the current state of the level without Mario (used initially)
void World::printLevelStateWithoutMario(Logger &logger) const {
    std::string levelState;
    for (int row = 0; row < gridDimension; ++row) {
        for (int col = 0; col < gridDimension; ++col) {
            levelState += levels[currentLevel].getItemAt(row, col);
        }
        if (row < gridDimension - 1) {
            levelState += '\n';
        }
    }
    logger.log(levelState);
    }


