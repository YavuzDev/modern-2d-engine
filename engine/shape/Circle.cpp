//
// Created by Emre on 6/15/2020.
//

#include <cmath>
#include <memory>
#include "Circle.h"
#include <GLFW\glfw3.h>

void Circle::draw(float screenWidth, float screenHeight) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(getColor().getRed(), getColor().getGreen(), getColor().getBlue());

    float convertedX = this->getPoints()[0]->getConvertedX(screenWidth);
    float convertedY = this->getPoints()[0]->getConvertedY(screenHeight);
    glVertex2f(convertedX, convertedY);

    for (float angle = 0; angle <= 2 * M_PI; angle += 0.01) {
        glBegin(GL_POINTS);
        glVertex2f(convertedX + std::cos(angle) * radius, convertedY + std::sin(angle) * radius);
    }
    glEnd();
}

Circle::Circle(Point point, float radius) {
    this->getPoints().push_back(std::make_shared<Point>(point));
    this->radius = radius;
}

void Circle::setRadius(float radius) {
    Circle::radius = radius;
}
