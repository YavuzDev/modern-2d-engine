//
// Created by Emre on 6/15/2020.
//

#include "Random.h"

int Random::random(int min, int max) {
    std::uniform_int_distribution<> range(min, max);
    return range(gen);
}

Random::Random() {
    this->gen = std::mt19937(rd());
}
