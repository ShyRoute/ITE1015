#pragma once

class Shape {
    public:
    Shape();
    Shape(int x, int y, int width, int height, char brush);
    double GetArea();
    int GetPerimeter();
    void Draw(int canvas_width, int canvas_height);

    protected:
    int _x;
    int _y;
    int _width;
    int _height;
    char _brush;
};

class Rectangle : public Shape {
    public:
    Rectangle(int x, int y, int width, int height, char brush);
};

class Square : public Shape {
    public:
    Square(int x, int y, int width, char brush);
};

class Diamond : public Shape {
    public:
    Diamond(int x, int y, int width, char brush);
    double GetArea();
    double GetPerimeter();
    void Draw(int canvas_width, int canvas_height);
};