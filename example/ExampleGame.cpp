//
// Created by Emre on 6/15/2020.
//

#include <iostream>
#include "ExampleGame.h"


ExampleGame::ExampleGame(int width, int height) : GameWindow(width, height) {
    auto rectangle = std::make_shared<Rectangle>(Point(50, 50), Dimension(50, 50));
    rectangle->setColor(Color(255, 100, 100));
    this->shapes.push_back(rectangle);

    auto line = std::make_shared<Line>(Point(0, 0), Point(static_cast<float>(width), static_cast<float>(height)));
    line->setColor(Color(0, 255, 100));
    this->shapes.push_back(line);

    auto circle = std::make_shared<Circle>(Point(static_cast<float>(width) / 2, static_cast<float>(height) / 2), 200);
    this->shapes.push_back(circle);
}

void ExampleGame::draw() {
    for (auto &shape : this->shapes) {
        shape->draw(static_cast<float>(getWidth()), static_cast<float>(getHeight()));
    }
}

void ExampleGame::onMouseButton(GLFWwindow *window, MouseEvents::MouseButtonEvent button,
                                MouseEvents::MouseActionEvent action, int mods) {
    if (action == MouseEvents::pressed) {
        auto rectangle = std::dynamic_pointer_cast<Rectangle>(this->shapes[0]);
        rectangle->getDimension().incrementWidth(button == MouseEvents::leftClick ? 50 : -50);
        rectangle->getDimension().incrementHeight(button == MouseEvents::leftClick ? 50 : -50);
        rectangle->setColor(Color(random.random(0, 255), random.random(0, 255), random.random(0, 255)));
    }
}

void ExampleGame::onMouseMove(GLFWwindow *window, double xPos, double yPos) {
    GameWindow::onMouseMove(window, xPos, yPos);

    this->shapes[0]->getPoints()[0]->setX(getCursorPoint().getX());
    this->shapes[0]->getPoints()[0]->setY(static_cast<float>(getHeight()) - getCursorPoint().getY());
}

void ExampleGame::onKeyboardButton(GLFWwindow *window, char key, int scancode, KeyboardEvents::KeyboardAction action, int mods) {

}

