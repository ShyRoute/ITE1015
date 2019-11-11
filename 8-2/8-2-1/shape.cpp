#include "shape.h"
#include <iostream>
#include <cmath>

Shape::Shape() {

}

Shape::Shape(int x, int y, int width, int height, char brush) {
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _brush = brush;
}

double Shape::GetArea() {
    return _width * _height;
}

int Shape::GetPerimeter() {
    return 2 * (_width + _height);
}

void Shape::Draw(int canvas_width, int canvas_height) {
    int x = canvas_width + 1;
    int y = canvas_height + 1;

    int cx = _x + 1;
    int cy = _y + 1;

    char **canvas = new char *[y];
    for(int i = 0; i < y; i++) canvas[i] = new char[x];

    for(int i = 0; i < y; i++) for(int j = 0; j < x; j++) canvas[i][j] = '.';
    canvas[0][0] = ' ';
    for(int i = 1; i < x; i++) canvas[0][i] = (i - 1) % 10 + '0';
    for(int i = 1; i < y; i++) canvas[i][0] = (i - 1) % 10 + '0';

    for(int i = cy; i < cy + _height; i++) {
        for(int j = cx; j < cx + _width; j++) {
            if(i < y && j < x) canvas[i][j] = _brush;
        }
    }

    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) std::cout << canvas[i][j];
        std::cout << '\n';
    }

    for(int i = 0; i < y; i++) delete[] canvas[i];
    delete[] canvas;
}

Rectangle::Rectangle(int x, int y, int width, int height, char brush) : Shape(x, y, width, height, brush) {

}

Square::Square(int x, int y, int width, char brush) : Shape(x, y, width, width, brush) {

}

Diamond::Diamond(int x, int y, int width, char brush) : Shape(x, y, width, width, brush) {

}

double Diamond::GetArea() {
    double x = _width * 2 + 1;
    return x * x / 2;
}

double Diamond::GetPerimeter() {
    double x = _width * 2 + 1 / 2;
    return std::ceil(std::sqrt(x * x + x * x)) * 4;
}

void Diamond::Draw(int canvas_width, int canvas_height) {
    int x = canvas_width + 1;
    int y = canvas_height + 1;

    int cx = _x + 1;
    int cy = _y + _width + 1;

    char **canvas = new char *[y];
    for(int i = 0; i < y; i++) canvas[i] = new char[x];

    for(int i = 0; i < y; i++) for(int j = 0; j < x; j++) canvas[i][j] = '.';
    canvas[0][0] = ' ';
    for(int i = 1; i < x; i++) canvas[0][i] = (i - 1) % 10 + '0';
    for(int i = 1; i < y; i++) canvas[i][0] = (i - 1) % 10 + '0';

    for(int i = 1; i < y; i++) {
        for(int j = 1; j < x; j++) {
            if(i < y && j < x) {
                if(std::abs(cx - j) + std::abs(cy - i) <= _width) {
                    canvas[i][j] = _brush;
                }
            }
        }
    }

    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) std::cout << canvas[i][j];
        std::cout << '\n';
    }

    for(int i = 0; i < y; i++) delete[] canvas[i];
    delete[] canvas;
}