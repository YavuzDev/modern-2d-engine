//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_EXAMPLEGAME_H
#define KIRAGED2DENGINE_EXAMPLEGAME_H


#include "../engine/GameWindow.h"
#include "../engine/util/Random.h"

class ExampleGame : public GameWindow {

private:
    Random random;

    std::vector<std::shared_ptr<Shape>> shapes;

protected:
    void draw() override;

    void onMouseButton(GLFWwindow *window, MouseEvents::MouseButtonEvent button, MouseEvents::MouseActionEvent action,
                       int mods) override;

    void onMouseMove(GLFWwindow *window, double xPos, double yPos) override;

public:
    ExampleGame(int width, int height);

};


#endif //KIRAGED2DENGINE_EXAMPLEGAME_H
