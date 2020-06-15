//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_RECTANGLE_H
#define KIRAGED2DENGINE_RECTANGLE_H


#include "Shape.h"
#include "../position/Dimension.h"

class Rectangle : public Shape {

private:
    Dimension dimension;

public:
    void draw(float screenWidth, float screenHeight) override;

    Rectangle(Point point, Dimension dimension);

    Dimension &getDimension();
};


#endif //KIRAGED2DENGINE_RECTANGLE_H
