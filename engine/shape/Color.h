//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_COLOR_H
#define KIRAGED2DENGINE_COLOR_H

class Color {
private:
    int red;

    int green;

    int blue;

public:
    Color(int red, int green, int blue) : red(red), green(green), blue(blue) {}

    int getRed() const {
        return red;
    }

    int getGreen() const {
        return green;
    }

    int getBlue() const {
        return blue;
    }
};

#endif //KIRAGED2DENGINE_COLOR_H
