// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#ifndef LEVEL_H
#define LEVEL_H

#include "Logger.h"

// Class to represent a level in the game
class Level {
public:
    Level();  // Constructor
    ~Level(); // Destructor

    void initialize(int gridDimension); // Initialize the grid
    void populate(int perCoins, int perEmpty, int perGoombas, int perKoopas, int perMushrooms); // Populate the grid
    void placeWarpPipe(); // Place a warp pipe in the grid
    void placeBoss(); // Place a boss in the grid
    char getItemAt(int row, int col) const; // Get item at specific grid position
    void setItemAt(int row, int col, char item); // Set item at specific grid position
    void printLevelState(Logger &logger, int marioRow, int marioCol) const;  // Add Mario's position
    void printLevelStateWithoutMario(Logger &logger) const; // Print the level state without Mario
    
private:
    char **grid; // 2D array for the grid
    int gridDimension; // Dimension of the grid
};

#endif