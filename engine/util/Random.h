//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_RANDOM_H
#define KIRAGED2DENGINE_RANDOM_H


#include <random>

class Random {
private:
    std::random_device rd;

public:
    int random(int min, int max);
};


#endif //KIRAGED2DENGINE_RANDOM_H
