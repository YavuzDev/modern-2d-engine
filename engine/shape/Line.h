//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_LINE_H
#define KIRAGED2DENGINE_LINE_H


#include "Shape.h"

class Line : public Shape {

public:
    int size() override;

    void draw(float screenWidth, float screenHeight) override;

    Line(Point firstPoint, Point secondPoint);
};


#endif //KIRAGED2DENGINE_LINE_H
