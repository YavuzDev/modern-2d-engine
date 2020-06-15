//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_SHAPE_H
#define KIRAGED2DENGINE_SHAPE_H


#include "../position/Point.h"
#include "Color.h"
#include <vector>

class Shape {

private:
    std::vector<std::shared_ptr<Point>> points;

    Color color = Color(255, 255, 255);

public:
    virtual void draw(float screenWidth, float screenHeight) = 0;

    std::vector<std::shared_ptr<Point>> &getPoints() {
        return points;
    }

    const Color &getColor() const {
        return color;
    }

    void setColor(const Color &color) {
        Shape::color = color;
    }
};


#endif //KIRAGED2DENGINE_SHAPE_H
