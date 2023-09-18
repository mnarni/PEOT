
#include "Boundary.h"

Boundary::Boundary(float width, float height): width(width), height(height) {}

Boundary::~Boundary() {}

float Boundary::getWidth() {
    return width;
}

float Boundary::getHeight() {
    return height;
}

void Boundary::setWidth(float width) {
    Boundary::width = width;
}

void Boundary::setHeight(float height) {
    Boundary::height = height;
}
