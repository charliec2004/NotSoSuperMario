// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#ifndef MARIO_H
#define MARIO_H

// Class to represent Mario in the game
class Mario {
public:
    Mario(int lives, int power, int row, int col);
    ~Mario();

    void setPosition(int row, int col);
    int getRow() const;
    int getCol() const;

    void collectCoin();
    void eatMushroom();
    bool encounterEnemy(char enemy);

    int getLives() const;
    int getCoins() const;
    int getPowerLevel() const;

    void setLives(int lives);

    void decreasePowerLevel(int power) {
        powerLevel -= power;
    }

    void loseLife() {
        lives--;
    }

    void setPowerLevel(int power) {
        powerLevel = power;
    }   

private:
    int lives;
    int powerLevel;
    int coins;
    int currentRow;
    int currentCol;
    int enemiesDefeated;
};

#endif