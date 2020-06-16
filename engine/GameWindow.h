//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_GAMEWINDOW_H
#define KIRAGED2DENGINE_GAMEWINDOW_H


#include <vector>
#include <memory>
#include "shape/Shape.h"
#include "shape/Triangle.h"
#include "shape/Rectangle.h"
#include "shape/Line.h"
#include "shape/Circle.h"
#include "position/Dimension.h"
#include "event/MouseEvents.h"
#include "event/KeyboardEvents.h"
#include <GLFW\glfw3.h>

class GameWindow {

private:
    int width;

    int height;

    Point cursorPoint = Point(0, 0);

protected:
    virtual void draw() = 0;

    virtual void
    onMouseButton(GLFWwindow *window, MouseEvents::MouseButtonEvent button, MouseEvents::MouseActionEvent action,
                  int mods) = 0;

    virtual void onMouseMove(GLFWwindow *window, double xPos, double yPos);

    virtual void onKeyboardButton(GLFWwindow *window, char key, int scancode, KeyboardEvents::KeyboardAction action, int mods) = 0;

    Point &getCursorPoint();

protected:

    int getWidth() const;

    int getHeight() const;

public:
    GameWindow(int width, int height);

    void start();
};


#endif //KIRAGED2DENGINE_GAMEWINDOW_H
