#pragma once
#include <vector>
#include <string>

class Canvas {
    public:
    Canvas();
    Canvas(size_t row, size_t col);
    ~Canvas();
    void Resize(size_t w, size_t h);
    void DrawPixel(int x, int y, char brush);
    void Print();
    void Clear();
    int getWidth();
    int getHeight();

    private:
    char **paper;
    int canvas_width;
    int canvas_height;
};

class Shape {
    public:
    Shape();
    Shape(int x, int y, int width, int height, char brush);
    virtual ~Shape();
    virtual void Draw(Canvas *canvas);
    virtual void printInfo();

    protected:
    std::string type;
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

class UpTriangle : public Shape {
    public:
    UpTriangle(int x, int y, int width, char brush);
    virtual void Draw(Canvas *canvas);
};

class DownTriangle : public Shape {
    public:
    DownTriangle(int x, int y, int width, char brush);
    virtual void Draw(Canvas *canvas);
};

class Diamond : public Shape {
    public:
    Diamond(int x, int y, int width, char brush);
    virtual void Draw(Canvas *canvas);
};