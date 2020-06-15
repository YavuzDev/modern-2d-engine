//
// Created by Emre on 6/15/2020.
//

#include "Point.h"

Point::Point(float x, float y) : x(x), y(y) {}

float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

void Point::setX(float x) {
    Point::x = x;
}

void Point::setY(float y) {
    Point::y = y;
}

float Point::getConvertedX(float screenWidth) const {
    float average = (-1 + screenWidth) / 2;
    float range = (screenWidth - -1) / 2;
    return (x - average) / range;
}

float Point::getConvertedY(float screenHeight) const {
    float average = (-1 + screenHeight) / 2;
    float range = (screenHeight - -1) / 2;
    return (y - average) / range;
}
