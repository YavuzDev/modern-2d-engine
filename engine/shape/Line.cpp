//
// Created by Emre on 6/15/2020.
//

#include <memory>
#include "Line.h"

void Line::draw(float screenWidth, float screenHeight) {
    glBegin(GL_LINES);
    glColor3ub(getColor().getRed(), getColor().getGreen(), getColor().getBlue());
    for (int i = 0; i < 2; i++) {
        glVertex2f(this->getPoints()[i]->getConvertedX(screenWidth), this->getPoints()[i]->getConvertedY(screenHeight));
    }
    glEnd();
}

Line::Line(Point firstPoint, Point secondPoint) {
    this->getPoints().push_back(std::make_shared<Point>(firstPoint));
    this->getPoints().push_back(std::make_shared<Point>(secondPoint));
}
