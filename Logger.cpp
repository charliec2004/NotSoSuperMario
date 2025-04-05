// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#include "Logger.h"
#include <iostream>

// Constructor: Opens the log file with the provided file name
Logger::Logger(const std::string& fileName) {
    logFile.open(fileName, std::ios::out | std::ios::trunc);  // Open in write mode, truncate existing file
    if (!logFile.is_open()) {
        std::cerr << "Error opening log file: " << fileName << std::endl;
    }
}

// Destructor: Closes the log file if it is open
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Logs a general message to the log file
void Logger::log(const std::string& message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
    } else {
        std::cerr << "Log file is not open for logging message: " << message << std::endl;
    }
}

// Logs the game state to the log file
void Logger::logGameState(const std::string& state) {
    if (logFile.is_open()) {
        logFile << state << std::endl;
    } else {
        std::cerr << "Log file is not open for logging game state: " << state << std::endl;
    }
}