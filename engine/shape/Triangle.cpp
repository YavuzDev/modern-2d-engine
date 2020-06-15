//
// Created by Emre on 6/15/2020.
//

#include "Triangle.h"
#include <GLFW\glfw3.h>

int Triangle::size() {
    return 6 * sizeof(float);
}

void Triangle::draw(float screenWidth, float screenHeight) {
    glBegin(GL_TRIANGLES);
    glColor3ub(getColor().getRed(), getColor().getGreen(), getColor().getBlue());
    for (int i = 0; i < 3; i++) {
        glVertex2f(this->getPoints()[i]->getConvertedX(screenWidth), this->getPoints()[i]->getConvertedY(screenHeight));
    }
    glEnd();
}

Triangle::Triangle(Point firstPoint, Point secondPoint, Point thirdPoint) {
    this->getPoints().push_back(std::make_shared<Point>(firstPoint));
    this->getPoints().push_back(std::make_shared<Point>(secondPoint));
    this->getPoints().push_back(std::make_shared<Point>(thirdPoint));
}

