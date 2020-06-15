//
// Created by Emre on 6/15/2020.
//

#include <algorithm>
#include <cmath>
#include "DrawingGame.h"

void DrawingGame::draw() {
    for (auto &shape : this->shapes) {
        shape->draw(static_cast<float>(getWidth()), static_cast<float>(getHeight()));
    }
}

void DrawingGame::onMouseButton(GLFWwindow *window, MouseEvents::MouseButtonEvent button,
                                MouseEvents::MouseActionEvent action, int mods) {
    this->drawing = action == MouseEvents::pressed && button == MouseEvents::leftClick;
    this->erasing = action == MouseEvents::pressed && button == MouseEvents::rightClick;
}

void DrawingGame::onMouseMove(GLFWwindow *window, double xPos, double yPos) {
    GameWindow::onMouseMove(window, xPos, yPos);

    if (this->drawing) {
        auto circle = std::make_shared<Circle>(
                Point(getCursorPoint().getX(), static_cast<float>(getHeight()) - getCursorPoint().getY()), 80);
        this->shapes.push_back(circle);
    }

    if (this->erasing) {
        this->shapes.erase(
                std::remove_if(this->shapes.begin(), this->shapes.end(), [&](const std::shared_ptr<Shape> &shape) {
                    auto deltaX = shape->getPoints()[0]->getX() - getCursorPoint().getX();
                    auto deltaY = shape->getPoints()[0]->getY() -
                                  (static_cast<float>(getHeight()) - getCursorPoint().getY());

                    auto distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

                    return distance < 50;
                }), this->shapes.end());
    }
}

DrawingGame::DrawingGame(int width, int height) : GameWindow(width, height) {}
