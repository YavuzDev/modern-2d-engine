//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_SHAPE_H
#define KIRAGED2DENGINE_SHAPE_H


#include "../position/Point.h"
#include <vector>

class Shape {

private:
    std::vector<std::shared_ptr<Point>> points;

public:
    virtual int size() = 0;

    virtual void draw(float screenWidth, float screenHeight) = 0;

    std::vector<std::shared_ptr<Point>> &getPoints() {
        return points;
    }
};


#endif //KIRAGED2DENGINE_SHAPE_H
