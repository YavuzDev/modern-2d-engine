//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_CIRCLE_H
#define KIRAGED2DENGINE_CIRCLE_H


#include "Shape.h"

class Circle : public Shape {

private:
    float radius;

public:
    void draw(float screenWidth, float screenHeight) override;

    Circle(Point point, float radius);

    void setRadius(float radius);
};


#endif //KIRAGED2DENGINE_CIRCLE_H
