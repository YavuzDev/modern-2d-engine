# Kiraged Engine

A 2d Game Engine built on OpenGL with GLFW.

# Example

This example is used to move the rectangle when the cursor moves and to set the width and height to increment or decrement by 50 based on the mouse click event.

```c++

#include <iostream>
#include "ExampleGame.h"


ExampleGame::ExampleGame(int width, int height) : GameWindow(width, height) {
    auto rectangle = std::make_shared<Rectangle>(Point(50, 50), Dimension(50, 50));
    rectangle->setColor(Color(100, 100, 100));
    this->shapes.push_back(rectangle);

    auto line = std::make_shared<Line>(Point(0, 0), Point(static_cast<float>(width), static_cast<float>(height)));
    line->setColor(Color(200, 200, 200));
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

```

To start the actual window:


```c++
#include "example/ExampleGame.h"

int main() {
    ExampleGame exampleGame(1000, 800);
    exampleGame.start();
    return 0;
}
```


# Second example

This example is used to draw and erase circles, by drawing with left mouse button and erasing with right mouse button. Also the canvas can be reset by pressing "r".

```c++

#include <algorithm>
#include <cmath>
#include <iostream>
#include "DrawingGame.h"

DrawingGame::DrawingGame(int width, int height) : GameWindow(width, height) {}

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
        circle->setColor(Color(random.random(0, 255), random.random(0, 255), random.random(0, 255)));
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

void DrawingGame::onKeyboardButton(GLFWwindow *window, char key, int scancode, KeyboardEvents::KeyboardAction action, int mods) {
    if (action == KeyboardEvents::pressed && key == 'R') {
        this->shapes.clear();
    }
}
```
