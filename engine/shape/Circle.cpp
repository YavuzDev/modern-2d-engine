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

    float x = this->getPoints()[0]->getConvertedX(screenWidth);
    float y = this->getPoints()[0]->getConvertedY(screenHeight);
    glVertex2f(x, y);
    for (int i = 0; i <= 20; i++) {
        glVertex2f(x + ((radius / screenWidth) * cos(static_cast<float>(i) * 2.0f * M_PI / 20.0f)),
                   y + ((radius / screenHeight) * sin(static_cast<float>(i) * 2.0f * M_PI / 20.0f)));
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
