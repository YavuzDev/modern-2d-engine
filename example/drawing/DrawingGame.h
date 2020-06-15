//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_DRAWINGGAME_H
#define KIRAGED2DENGINE_DRAWINGGAME_H


#include "../../engine/GameWindow.h"
#include "../../engine/util/Random.h"

class DrawingGame : public GameWindow {

private:
    Random random;

    std::vector<std::shared_ptr<Shape>> shapes;

    bool drawing = false;

    bool erasing = false;

protected:
    void draw() override;

    void onMouseButton(GLFWwindow *window, MouseEvents::MouseButtonEvent button, MouseEvents::MouseActionEvent action,
                       int mods) override;

    void onMouseMove(GLFWwindow *window, double xPos, double yPos) override;

public:
    DrawingGame(int width, int height);
};


#endif //KIRAGED2DENGINE_DRAWINGGAME_H
