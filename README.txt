AUTHORS INFO:
Charlie Conner & Brett Abitante
2450953 & 2443690
chconner@chapman.edu & abitante@chapman.edu
CPSC-350-01
Assignment 2: Not So Super Mario Bros.

ERRORS: 
- no known compiler errors
- small output print statements may not be exact

HOW TO COMPILE/RUN: (ran in docker terminal)
- g++ -o test *.cpp
- ./test input.txt output.txt


SOURCES: 
- used assignment with details for guidance/format
- zybooks/in class notes
- https://stackoverflow.com/questions/478075/creating-files-in-c for output file help
- https://www.martystepp.com/cppdoc/Grid-class.html#:~:text=Grid()%3B%20Grid(int%20nRows,number%20of%20rows%20and%20columns. for help with creating a grid
- https://www.w3schools.com/cpp/cpp_switch.asp for simplifying switch statements
- https://www.w3schools.com/cpp/ref_ctime_ctime.asp#:~:text=The%20ctime()%20function%20returns,see%20the%20strftime()%20function. for how to use ctime function
- CHATGPT USAGE:
In Util.cpp (lines 12-24)
"How can I use the getRandomDirection() function in my code to randomly return one of four directions (UP, DOWN, LEFT, RIGHT)"
Direction Util::getRandomDirection() {
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
    return UP;
}

    In World.cpp (lines 183-188 )
    "Help me use a function that logs the level's number in a grid format using Logger reference while it excludes Mario's position"
for (int row = 0; row < gridDimension; ++row) {
        for (int col = 0; col < gridDimension; ++col) {
            levelState += levels[currentLevel].getItemAt(row, col);
        }
        if (row < gridDimension - 1) {
            levelState += '\n';
}
}

In Mario.cpp (lines 56-65)
"Help me make a function for Mario to handle encounters with enemies (g, k, b), and give specific win chances based on the enemy"
bool Mario::encounterEnemy(char enemy) {
    int chance = rand() % 100;  // Generate a random chance between 0 and 99
    bool won = false;

    if (enemy == 'g') {  // Encounter with Goomba
        won = (chance < 80);  // 80% chance of winning
    } else if (enemy == 'k') {  // Encounter with Koopa
        won = (chance < 65);  // 65% chance of winning
    } else if (enemy == 'b') {  // Encounter with Boss
        won = (chance < 50);  // 50% chance of winning
    }
}