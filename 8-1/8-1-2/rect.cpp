#include <iostream>
#include "rect.h"

Rectangle::Rectangle(int width, int height) {
    _width = width;
    _height = height;
}

int Rectangle::getArea() {
    return _width * _height;
}

int Rectangle::getPerimeter() {
    return 2 * (_width + _height);
}


Square::Square(int width) : Rectangle(width, width) {

}

void Square::print() {
    std::cout << _width << 'x' << _height << " Square" << std::endl;
}

NonSquare::NonSquare(int width, int height) : Rectangle(width, height) {
}

void NonSquare::print() {
    std::cout << _width << 'x' << _height << " NonSquare" << std::endl;
}
