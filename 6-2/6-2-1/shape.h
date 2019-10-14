#pragma once

class Circle {
    private:
    double _x;
    double _y;
    double _radius;

    public:
    void set(double x, double y, double r);
    double get_area();
    double get_perimeter();
};

class Rectangle {
    private:
    double _top_left_x;
    double _top_left_y;
    double _bottom_right_x;
    double _bottom_right_y;

    public:
    void set(double lx, double ly, double rx, double ry);
    double get_area();
    double get_perimeter();
};