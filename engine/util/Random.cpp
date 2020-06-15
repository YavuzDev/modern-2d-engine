//
// Created by Emre on 6/15/2020.
//

#include "Random.h"

int Random::random(int min, int max) {
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> range(min, max);
    return range(gen);
}
