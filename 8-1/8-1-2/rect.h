#pragma once

class Rectangle {
    public:
    Rectangle(int width, int height);
    int getArea();
    int getPerimeter();
    
    protected:
    int _width;
    int _height;
};

class Square : public Rectangle {
    public:
    Square(int width);
    void print();
};

class NonSquare : public Rectangle {
    public:
    NonSquare(int width, int height);
    void print();
};