// Charlie Conner & Brett Abitante
// 2450953 & 2443690
// chconner@chapman.edu & abitante@chapman.edu
// CPSC-350-01
// Assignment 2: Not So Super Mario Bros.

#ifndef UTIL_H
#define UTIL_H

enum Direction { UP, DOWN, LEFT, RIGHT };

class Util {
public:
    Direction getRandomDirection();
};

#endif