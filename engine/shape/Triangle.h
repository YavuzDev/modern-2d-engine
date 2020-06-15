//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_TRIANGLE_H
#define KIRAGED2DENGINE_TRIANGLE_H


#include <vector>
#include <memory>
#include "Shape.h"

class Triangle : public Shape {

public:
    void draw(float screenWidth, float screenHeight) override;

    Triangle(Point firstPoint, Point secondPoint, Point thirdPoint);
};


#endif //KIRAGED2DENGINE_TRIANGLE_H
