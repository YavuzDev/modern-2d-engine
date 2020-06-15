//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_RANDOM_H
#define KIRAGED2DENGINE_RANDOM_H


#include <random>

class Random {
private:
    std::random_device rd;

    std::mt19937 gen;

public:
    int random(int min, int max);

    Random();
};


#endif //KIRAGED2DENGINE_RANDOM_H
