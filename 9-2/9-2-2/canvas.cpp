#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "canvas.h"

Canvas::Canvas() {

}

Canvas::Canvas(size_t row, size_t col) {
    canvas_height = row;
    canvas_width = col;

    int x = canvas_width + 1;
    int y = canvas_height + 1;

    paper = new char *[y];
    for(int i = 0; i < y; i++) paper[i] = new char[x];
}

Canvas::~Canvas() {
    for(int i = 0; i < canvas_height + 1; i++) delete[] paper[i];
    delete[] paper;
}

void Canvas::Resize(size_t w, size_t h) {
    for(int i = 0; i < canvas_height + 1; i++) delete[] paper[i];
    delete[] paper;

    canvas_width = w;
    canvas_height = h;

    int x = canvas_width + 1;
    int y = canvas_height + 1;

    paper = new char *[y];
    for(int i = 0; i < y; i++) paper[i] = new char[x];
}

void Canvas::DrawPixel(int x, int y, char brush) {
    paper[x][y] = brush;
}

void Canvas::Print() {
    for(int i = 0; i < canvas_height + 1; i++) {
        for(int j = 0; j < canvas_width + 1; j++) std::cout << paper[i][j];
        std::cout << '\n';
    }
}

void Canvas::Clear() {
    int x = canvas_width + 1;
    int y = canvas_height + 1;

    for(int i = 0; i < y; i++) for(int j = 0; j < x; j++) paper[i][j] = '.';
    paper[0][0] = ' ';
    for(int i = 1; i < x; i++) paper[0][i] = (i - 1) % 10 + '0';
    for(int i = 1; i < y; i++) paper[i][0] = (i - 1) % 10 + '0';
}

int Canvas::getWidth() {
    return canvas_width;
}

int Canvas::getHeight() {
    return canvas_height;
}

Shape::Shape() {

}

Shape::Shape(int x, int y, int width, int height, char brush) {
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _brush = brush;
}

Shape::~Shape() {

}

void Shape::Draw(Canvas *canvas) {
    int x = canvas->getWidth() + 1;
    int y = canvas->getHeight() + 1;

    int cx = _x + 1;
    int cy = _y + 1;

    for(int i = cy; i < cy + _height; i++) {
        for(int j = cx; j < cx + _width; j++) {
            if(i < y && j < x) canvas->DrawPixel(i, j, _brush);
        }
    }
}

void Shape::printInfo() {
    std::cout << type << ' ' << _x << ' ' << _y << ' ' << _width << ' ' << _height << ' ' << _brush << std::endl;
}

Rectangle::Rectangle(int x, int y, int width, int height, char brush) : Shape(x, y, width, height, brush) {
    this->type = "rect";
}

UpTriangle::UpTriangle(int x, int y, int width, char brush) : Shape(x, y, width, width, brush) {
    this->type = "tri_up";
}

void UpTriangle::Draw(Canvas *canvas) {
    int x = canvas->getWidth() + 1;
    int y = canvas->getHeight() + 1;

    int cx = _x + 1;
    int cy = _y + _width;

    for(int i = 1; i < y; i++) {
        for(int j = 1; j < x; j++) {
            if(i < y && j < x) {
                if(i<=cy && std::abs(cx - j) + std::abs(cy - i) <= _width - 1) {
                    canvas->DrawPixel(i, j, _brush);
                }
            }
        }
    }
}

DownTriangle::DownTriangle(int x, int y, int width, char brush) : Shape(x, y, width, width, brush) {
    this->type = "tri_down";
}

void DownTriangle::Draw(Canvas *canvas) {
    int x = canvas->getWidth() + 1;
    int y = canvas->getHeight() + 1;

    int cx = _x + 1;
    int cy = _y - _width + 2;

    for(int i = 1; i < y; i++) {
        for(int j = 1; j < x; j++) {
            if(i < y && j < x) {
                if(i >= cy && std::abs(cx - j) + std::abs(cy - i) <= _width - 1) {
                    canvas->DrawPixel(i, j, _brush);
                }
            }
        }
    }
}

Diamond::Diamond(int x, int y, int width, char brush) : Shape(x, y, width, width, brush) {
    this->type = "diamond";
}

void Diamond::Draw(Canvas *canvas) {
    int x = canvas->getWidth() + 1;
    int y = canvas->getHeight() + 1;

    int cx = _x + 1;
    int cy = _y + _width + 1;

    for(int i = 1; i < y; i++) {
        for(int j = 1; j < x; j++) {
            if(i < y && j < x) {
                if(std::abs(cx - j) + std::abs(cy - i) <= _width) {
                    canvas->DrawPixel(i, j, _brush);
                }
            }
        }
    }
}
