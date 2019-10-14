#include "shape.h"
#include <iostream>

int main(void) {
    std::string shape;
    while(true) {
	std::cout << "Shape?\n";
        std::cin >> shape;
        if(shape == "C") {
            Circle c;
            int x, y, r;
            std::cin >> x >> y >> r;
            c.set(x, y, r);
            std::cout << "Area: " << c.get_area() << ", Perimeter: " << c.get_perimeter() << "\n\n";
        }

        else if(shape == "R") {
            Rectangle r;
            int a, b, c, d;
            std::cin >> a >> b >> c >> d;
            r.set(a, b, c, d);
            std::cout << "Area: " << r.get_area() << ", Perimeter: " << r.get_perimeter() << "\n\n";
        }

        else if(shape == "Q") {
            break;
        }
    }
    return 0;
}
