// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

// Class to log messages to a file
class Logger {
public:
    Logger(const std::string &fileName);
    ~Logger();

    void log(const std::string &message);
    void logGameState(const std::string &state);

private:
    std::ofstream logFile;
};

#endif