// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#include "Util.h"
#include <cstdlib>
#include <ctime>    // For time()

// Function to get a random direction (UP, DOWN, LEFT, RIGHT)

/*"""BEGIN CODE FROM CHAT GPT, PROMPT ASKED: how do you create a method that produces a random 2D direction from a random seed ? """ */

Direction Util::getRandomDirection() {

/*"""END OF CODE FROM CHAT GPT"""*/


    int randValue = rand() % 4;
    switch (randValue) {
        case 0:
            return UP;
        case 1:
            return DOWN;
        case 2:
            return LEFT;
        case 3:
            return RIGHT;
    }
    return UP; // this should never be reached
}

// Function to get a random number between 0 and max (inclusive)
int getRandomNumber(int max) {
    // seed the random number generator (only once)
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    return rand() % (max + 1);
}