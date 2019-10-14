#include "shape.h"

void Circle::set(double x, double y, double r) {
    _x = x;
    _y = y;
    _radius = r;
}

double Circle::get_area() {
    return _radius * _radius * 3.14;
}

double Circle::get_perimeter() {
    return 2 * _radius * 3.14;
}

void Rectangle::set(double lx, double ly, double rx, double ry) {
    _top_left_x = lx;
    _top_left_y = ly;
    _bottom_right_x = rx;
    _bottom_right_y = ry;
}

double Rectangle::get_area() {
    int a = _bottom_right_x - _top_left_x;
    int b = _top_left_y - _bottom_right_y;

    return 2 * (a + b);
}

double Rectangle::get_perimeter() {
    int a = _bottom_right_x - _top_left_x;
    int b = _top_left_y - _bottom_right_y;

    return a * b;
}