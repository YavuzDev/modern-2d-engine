//
// Created by Emre on 6/15/2020.
//

#include <memory>
#include "Rectangle.h"
#include "Triangle.h"

void Rectangle::draw(float screenWidth, float screenHeight) {
    auto firstPoint = this->getPoints()[0];
    auto secondPoint = Point(firstPoint->getX() + static_cast<float>(dimension.getWidth()), firstPoint->getY());
    auto thirdPoint = Point(firstPoint->getX(), firstPoint->getY() + static_cast<float>(dimension.getHeight()));

    auto firstTriangle = std::make_shared<Triangle>(*firstPoint, secondPoint, thirdPoint);
    firstTriangle->setColor(getColor());
    firstTriangle->draw(screenWidth, screenHeight);

    auto fourthPoint = Point(firstPoint->getX() + static_cast<float>(dimension.getWidth()),
                             firstPoint->getY() + static_cast<float>(dimension.getHeight()));
    auto fifthPoint = Point(firstPoint->getX() + static_cast<float>(dimension.getWidth()), firstPoint->getY());
    auto sixthPoint = Point(firstPoint->getX(), firstPoint->getY() + static_cast<float>(dimension.getHeight()));

    auto secondTriangle = std::make_shared<Triangle>(fourthPoint, fifthPoint, sixthPoint);
    secondTriangle->setColor(getColor());
    secondTriangle->draw(screenWidth, screenHeight);
}

Rectangle::Rectangle(Point point, Dimension dimension) : dimension(dimension) {
    this->getPoints().push_back(std::make_shared<Point>(point));
}

Dimension &Rectangle::getDimension() {
    return dimension;
}
