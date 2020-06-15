//
// Created by Emre on 6/15/2020.
//

#ifndef KIRAGED2DENGINE_DIMENSION_H
#define KIRAGED2DENGINE_DIMENSION_H


class Dimension {
private:
    int width;

    int height;

public:

    Dimension(int width, int height);

    int getWidth() const;

    int getHeight() const;

    void setWidth(int width);

    void setHeight(int height);

    void incrementWidth(int toAdd);

    void incrementHeight(int toAdd);
};


#endif //KIRAGED2DENGINE_DIMENSION_H
