// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>

// Class to process the input file and store the values
class FileProcessor {
public:
    FileProcessor();  
    ~FileProcessor(); 

    void processFile(const std::string& inputFileName);

    int getNumOfLevels() const;
    int getGridDimension() const;
    int getNumOfInitialLives() const;
    int getPercentageCoins() const;
    int getPercentageEmpty() const;
    int getPercentageGoombas() const;
    int getPercentageKoopas() const;
    int getPercentageMushrooms() const;

private:
    int numOfLevels;
    int gridDimension;
    int numOfInitialLives;
    int percentageCoins;
    int percentageEmpty;
    int percentageGoombas;
    int percentageKoopas;
    int percentageMushrooms;
};

#endif