// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#include "Level.h"
#include <iostream>
#include <cstdlib>

// Constructor: Initialize grid to nullptr and grid dimension to 0
Level::Level() : grid(nullptr), gridDimension(0) {}

// Destructor: Free dynamically allocated memory for the grid
Level::~Level() {
    if (grid) {
        for (int i = 0; i < gridDimension; ++i) {
            delete[] grid[i];
        }
        delete[] grid;
    }
}

// Initialize the grid with the given dimension and fill with empty spaces
void Level::initialize(int gridDimension) {
    this->gridDimension = gridDimension;
    grid = new char*[gridDimension];
    for (int i = 0; i < gridDimension; ++i) {
        grid[i] = new char[gridDimension];
        for (int j = 0; j < gridDimension; ++j) {
            grid[i][j] = 'x';  // Initialize all positions to empty ('x')
        }
    }
}

// Populate the grid with items based on the given percentages
void Level::populate(int perCoins, int perEmpty, int perGoombas, int perKoopas, int perMushrooms) {
    int totalCells = gridDimension * gridDimension;
    int numCoins = (perCoins * totalCells) / 100;
    int numGoombas = (perGoombas * totalCells) / 100;
    int numKoopas = (perKoopas * totalCells) / 100;
    int numMushrooms = (perMushrooms * totalCells) / 100;

    while (numCoins > 0 || numGoombas > 0 || numKoopas > 0 || numMushrooms > 0) {
        int row = rand() % gridDimension;
        int col = rand() % gridDimension;

        if (grid[row][col] == 'x') {  // Only place in empty spots
            if (numCoins > 0) {
                grid[row][col] = 'c';
                numCoins--;
            } else if (numGoombas > 0) {
                grid[row][col] = 'g';
                numGoombas--;
            } else if (numKoopas > 0) {
                grid[row][col] = 'k';
                numKoopas--;
            } else if (numMushrooms > 0) {
                grid[row][col] = 'm';
                numMushrooms--;
            }
        }
    }
}

// Place a warp pipe at a random empty position
void Level::placeWarpPipe() {
    int row, col;
    do {
        row = rand() % gridDimension;
        col = rand() % gridDimension;
    } while (grid[row][col] != 'c' && grid[row][col] != 'g' &&
             grid[row][col] != 'k' && grid[row][col] != 'm');  // Check for specific elements

    // Place warp pipe in the selected cell
    grid[row][col] = 'w';
}

// Place the boss at a random empty position
void Level::placeBoss() {
    int row, col;
    do {
        row = rand() % gridDimension;
        col = rand() % gridDimension;
    } while (grid[row][col] != 'x' && grid[row][col] != 'c' &&
             grid[row][col] != 'g' && grid[row][col] != 'k' &&
             grid[row][col] != 'm');  // Check for x, c, g, k, or m

    // Place the boss in the selected cell
    grid[row][col] = 'b';
}

// Get the item at the specified grid position
char Level::getItemAt(int row, int col) const {
    return grid[row][col];
}

// Set the item at the specified grid position
void Level::setItemAt(int row, int col, char item) {
    grid[row][col] = item;
}

// Print the state of the level grid to the logger
void Level::printLevelState(Logger &logger, int marioRow, int marioCol) const {
    for (int i = 0; i < gridDimension; ++i) {
        std::string row;
        for (int j = 0; j < gridDimension; ++j) {
            if (i == marioRow && j == marioCol) {
                row += 'H';  // Display Mario's position
            } else {
                row += grid[i][j];
            }
        }
        logger.log(row);
    }
}

// Print the state of the level grid without Mario to the logger
void Level::printLevelStateWithoutMario(Logger &logger) const {
    for (int i = 0; i < gridDimension; ++i) {
        for (int j = 0; j < gridDimension; ++j) {
            logger.log(std::string(1, grid[i][j]) + " ");
        }
        logger.log("\n");
    }
}
