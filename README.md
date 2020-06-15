# Kiraged Engine

A 2d Game Engine built on OpenGL with GLFW.

# Example

This example is used to move the rectangle when the cursor moves and to set the width and height to the cursor position.

```c++

#include <iostream>
#include "ExampleGame.h"


ExampleGame::ExampleGame(int width, int height) : GameWindow(width, height) {
    auto rectangle = std::make_shared<Rectangle>(Point(50, 50), Dimension(50, 50));
    this->shapes.push_back(rectangle);
}

void ExampleGame::draw() {
    for (auto &shape : this->shapes) {
        shape->draw(static_cast<float>(getWidth()), static_cast<float>(getHeight()));
    }
}

void ExampleGame::onMouseButton(GLFWwindow *window, MouseEvents::MouseButtonEvent button, MouseEvents::MouseActionEvent action, int mods) {
    if (action == MouseEvents::MouseActionEvent::pressed) {
        auto rectangle = std::dynamic_pointer_cast<Rectangle>(this->shapes[0]);
        rectangle->getDimension().setWidth(static_cast<int>(getCursorPoint().getX()));
        rectangle->getDimension().setHeight(static_cast<int>(getCursorPoint().getY()));
    }
}

void ExampleGame::onMouseMove(GLFWwindow *window, double xPos, double yPos) {
    GameWindow::onMouseMove(window, xPos, yPos);

    this->shapes[0]->getPoints()[0]->setX(static_cast<float>(xPos));
    this->shapes[0]->getPoints()[0]->setY(static_cast<float>(getHeight() - yPos));
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
