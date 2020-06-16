//
// Created by Emre on 6/15/2020.
//

#include "GameWindow.h"
#include <GLFW\glfw3.h>
#include <stdexcept>


void GameWindow::start() {
    if (!glfwInit()) {
        throw std::runtime_error("Unable to initialize glfw");
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow *window = glfwCreateWindow(width, height, "Game", nullptr, nullptr);

    glfwSetWindowUserPointer(window, this);

    auto mouseButtonCallback = [](GLFWwindow *w, int button, int action, int mods) {
        static_cast<GameWindow *>(glfwGetWindowUserPointer(w))->
                onMouseButton(w,
                              static_cast<MouseEvents::MouseButtonEvent>(button),
                              static_cast<MouseEvents::MouseActionEvent>(action),
                              mods);
    };
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    auto mouseMovementCallback = [](GLFWwindow *w, double xPos, double yPos) {
        static_cast<GameWindow *>(glfwGetWindowUserPointer(w))->onMouseMove(w, xPos, yPos);
    };
    glfwSetCursorPosCallback(window, mouseMovementCallback);

    auto keyboardButtonCallback = [](GLFWwindow *w, int key, int scancode, int action, int mods) {
        static_cast<GameWindow *>(glfwGetWindowUserPointer(w))->
                onKeyboardButton(w, static_cast<char>(key), scancode,
                                 static_cast<KeyboardEvents::KeyboardAction>(action),
                                 mods);
    };
    glfwSetKeyCallback(window, keyboardButtonCallback);

    glfwMakeContextCurrent(window);

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        draw();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
}

GameWindow::GameWindow(int width, int height) : width(width), height(height) {}

int GameWindow::getWidth() const {
    return width;
}

int GameWindow::getHeight() const {
    return height;
}

Point &GameWindow::getCursorPoint() {
    return cursorPoint;
}

void GameWindow::onMouseMove(GLFWwindow *window, double xPos, double yPos) {
    cursorPoint.setX(static_cast<float>(xPos));
    cursorPoint.setY(static_cast<float>(yPos));
}
