//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_POINT_H
#define KIRAGED2DENGINE_POINT_H


class Point {

private:
    float x;

    float y;

public:
    Point(float x, float y);

    float getX() const;

    float getY() const;

    float getConvertedX(float screenWidth) const;

    float getConvertedY(float screenHeight) const;

    void setX(float x);

    void setY(float y);
};


#endif //KIRAGED2DENGINE_POINT_H
