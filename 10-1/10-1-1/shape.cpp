#include <iostream>

#include "shape.h"

Shape::Shape(double w, double h) {
    width_ = w;
    height_ = h;
}

Triangle::Triangle(double w, double h) : Shape(w, h) {

}

double Triangle::getArea() {
    return width_ * height_ / 2;
}

Rectangle::Rectangle(double w, double h) : Shape(w, h) {

}

double Rectangle::getArea() {
    return width_ * height_;
}