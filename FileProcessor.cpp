// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#include "FileProcessor.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
// Constructor
FileProcessor::FileProcessor() : numOfLevels(0), gridDimension(0), numOfInitialLives(0),
                                 percentageCoins(0), percentageEmpty(0),
                                 percentageGoombas(0), percentageKoopas(0), percentageMushrooms(0) {}
// Destructor
FileProcessor::~FileProcessor() {}

// Process the input file and store the values in the class members
void FileProcessor::processFile(const std::string& inputFileName) {
    std::ifstream inputFile(inputFileName);
    // Check if the input file is open
    if (!inputFile.is_open()) {
        throw std::runtime_error("input file not opened");
    } 

    // Read the values from the input file
    inputFile >> numOfLevels >> gridDimension >> numOfInitialLives
              >> percentageCoins >> percentageEmpty >> percentageGoombas
              >> percentageKoopas >> percentageMushrooms;
    // Check if the percentages sum to 100
    if (percentageCoins + percentageEmpty + percentageGoombas + 
        percentageKoopas + percentageMushrooms != 100) {
        throw std::runtime_error("percentages in input file do not sum to 100.");
    }
    // Close the input file
    inputFile.close();
}

// Getters for the class members
int FileProcessor::getNumOfLevels() const { return numOfLevels; }
int FileProcessor::getGridDimension() const { return gridDimension; }
int FileProcessor::getNumOfInitialLives() const { return numOfInitialLives; }
int FileProcessor::getPercentageCoins() const { return percentageCoins; }
int FileProcessor::getPercentageEmpty() const { return percentageEmpty; }
int FileProcessor::getPercentageGoombas() const { return percentageGoombas; }
int FileProcessor::getPercentageKoopas() const { return percentageKoopas; }
int FileProcessor::getPercentageMushrooms() const { return percentageMushrooms; }