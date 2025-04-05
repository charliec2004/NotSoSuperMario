// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#include "Mario.h"
#include <iostream>
#include <cstdlib>  // For rand() function

// Constructor to initialize Mario's attributes
Mario::Mario(int lives, int power, int row, int col)
    : lives(lives), powerLevel(power), coins(0), currentRow(row), currentCol(col), enemiesDefeated(0) {}

// Destructor: No dynamic memory to clean up, so it's empty
Mario::~Mario() {}

// Sets Mario's position on the grid
void Mario::setPosition(int row, int col) {
    currentRow = row;
    currentCol = col;
}

// Set Mario's lives
void Mario::setLives(int lives) { 
    this->lives = lives;
}

// Returns Mario's current row position
int Mario::getRow() const {
    return currentRow;
}

// Returns Mario's current column position
int Mario::getCol() const {
    return currentCol;
}

// Increment Mario's coin count and possibly lives
void Mario::collectCoin() {
    coins++;
    if (coins == 20) { 
        lives++;
        coins = 0;
    }
}

// Increase Mario's power level by eating a mushroom
void Mario::eatMushroom() {
    if (powerLevel < 2) {  // Max power level is 2
        powerLevel++;
    }
}

// Handle Mario's encounter with an enemy, returns true if Mario wins
bool Mario::encounterEnemy(char enemy) {
    int chance = rand() % 100;  // Generate a random chance between 0 and 99
    bool won = false;

    if (enemy == 'g') {  // Encounter with Goomba
        won = (chance < 80);  // 80% chance of winning
    } else if (enemy == 'k') {  // Encounter with Koopa
        won = (chance < 65);  // 65% chance of winning
    } else if (enemy == 'b') {  // Encounter with Boss
        won = (chance < 50);  // 50% chance of winning
    }

    if (won) {
        enemiesDefeated++;
        if (enemiesDefeated == 7) {  // Earn an extra life after defeating 7 enemies in the same life
            lives++;
            enemiesDefeated = 0;  // Reset the counter
        }
        return true;  // Mario won the encounter
    } else {
        powerLevel--;  // Lose a power level
        if (powerLevel < 0) {  // If power level drops below 0
            powerLevel = 0;  // Reset to PL0
            lives--;  // Lose a life
            enemiesDefeated = 0;  // Reset the counter on life loss
            if (lives <= 0) {  // If no lives left, game over
                std::cout << "Mario has lost all lives!" << std::endl;
                return false;  // Mario lost the game
            }
        }
        return false;  // Mario lost the encounter
    }
}

// Get the number of lives Mario has
int Mario::getLives() const {
    return lives;
}

// Get the number of coins Mario has collected
int Mario::getCoins() const {
    return coins;
}

// Get Mario's current power level
int Mario::getPowerLevel() const {
    return powerLevel;
}