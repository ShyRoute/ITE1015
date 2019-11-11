#include <iostream>
#include <string>
#include "shape.h"

int main(void) {
    int a, b, x, y, cx, cy;
    char brush;
    std::string work;

    std::cin >> cx >> cy;

    while(true) {
        std::cin >> work;
        
        if(work == "rect") {
            std::cin >> x >> y >> a >> b >> brush;
            Rectangle rect(x, y, a, b, brush);
            std::cout << "Area: " << rect.GetArea() << std::endl;
            std::cout << "Perimeter: " << rect.GetPerimeter() << std::endl;
            rect.Draw(cx, cy);
        }

        else if(work == "square") {
            std::cin >> x >> y >> a >> brush;
            Square sq(x, y, a, brush);
            std::cout << "Area: " << sq.GetArea() << std::endl;
            std::cout << "Perimeter: " << sq.GetPerimeter() << std::endl;
            sq.Draw(cx, cy);
        }

        else if(work == "diamond") {
            std::cin >> x >> y >> a >> brush;
            Diamond dia(x, y, a, brush);
            std::cout << "Area: " << dia.GetArea() << std::endl;
            std::cout << "Perimeter: " << dia.GetPerimeter() << std::endl;
            dia.Draw(cx, cy);
        }

        else if(work == "quit") {
            break;
        }
    }

    return 0;
}