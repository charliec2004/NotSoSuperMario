// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#include "FileProcessor.h"
#include "World.h"
#include "Logger.h"
#include <iostream>
#include <stdexcept>
#include <ctime>  // Include ctime for time()

int main(int argc, char* argv[]) {
    if (argc != 3) { // Check if the correct number of arguments is provided
        std::cerr << "Usage: " << argv[0] << " <input_file> <log_file>" << std::endl;
        return 1;
    }

    std::string inputFileName = argv[1];
    std::string logFileName = argv[2];


/*"""BEGIN CODE FROM CHAT GPT, PROMPT ASKED: how do I seed my random number generator in c++?*/
srand(static_cast<unsigned int>(time(0)));
/*"""END OF CODE FROM CHAT GPT"""*/


    // Seed the random number generator with the current tim

    try {
        // Create and process the input file using FileProcessor
        FileProcessor fileProcessor;
        fileProcessor.processFile(inputFileName);

        // Create the Logger object to record game events
        Logger logger(logFileName);

        // Create the World object using 8 parameters, including the percentage of empty spaces
        World world(fileProcessor.getNumOfLevels(),
                    fileProcessor.getGridDimension(),
                    fileProcessor.getNumOfInitialLives(),
                    fileProcessor.getPercentageCoins(),
                    fileProcessor.getPercentageEmpty(),
                    fileProcessor.getPercentageGoombas(),
                    fileProcessor.getPercentageKoopas(),
                    fileProcessor.getPercentageMushrooms());

        // Initialize the game world
        world.initialize();
        
        // Log the initial state of the world
        world.logState(logger);

        // Main game loop: Update game state until the game is over
        while (world.updateGameState(logger)) {
            world.printWorldState(logger);  // Print the state of the world to the log file
        }

        std::cout << "Game over!" << std::endl;  // Print message when the game ends
    }
    catch (const std::exception &e) {  // Catch and handle any exceptions
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;  // Exit the program successfully
}