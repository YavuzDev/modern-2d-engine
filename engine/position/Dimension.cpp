//
// Created by Emre on 6/15/2020.
//

#include "Dimension.h"

int Dimension::getWidth() const {
    return width;
}

int Dimension::getHeight() const {
    return height;
}

void Dimension::setWidth(int width) {
    Dimension::width = width;
}

void Dimension::setHeight(int height) {
    Dimension::height = height;
}

Dimension::Dimension(int width, int height) : width(width), height(height) {}

void Dimension::incrementWidth(int toAdd) {
    Dimension::width += toAdd;
}

void Dimension::incrementHeight(int toAdd) {
    Dimension::height += toAdd;
}
