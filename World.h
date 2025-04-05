// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#ifndef WORLD_H
#define WORLD_H

#include "Mario.h"
#include "Level.h"
#include "Logger.h"
#include "Util.h"

class World {
public:
    // Update constructor to take 8 parameters
    World(int levels, int dimension, int lives, int perCoins, int perEmpty, int perGoombas, int perKoopas, int perMushrooms);
    ~World();

    void initialize();
    void moveMario(Logger &logger);
    void handleInteraction(Logger &logger);
    bool updateGameState(Logger &logger);
    void logState(Logger &logger);
    void printWorldState(Logger &logger) const;
    void printLevelStateWithoutMario(Logger &logger) const;

private:
    int numberOfLevels;
    int gridDimension;
    int initialLives;
    int percentageCoins;
    int percentageEmpty;     // Add percentageEmpty as a class member
    int percentageGoombas;
    int percentageKoopas;
    int percentageMushrooms;
    Mario *mario;
    Level levels[10];
    int currentLevel;

    bool isFinalBossDefeated();
    void setupLevels();
};

#endif