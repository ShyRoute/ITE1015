#include <iostream>
#include <string>
#include "rect.h"

int main(void) {
    int a, b;
    std::string work;

    while(true) {
        std::cin >> work;

        if(work == "nonsquare") {
            std::cin >> a >> b;
            NonSquare n(a,b);
            n.print();
            std::cout << "Area: " << n.getArea()<<std::endl;
            std::cout << "Perimeter: " << n.getPerimeter() << std::endl;
        }

        else if(work == "square") {
            std::cin >> a;
            Square n(a);
            n.print();
            std::cout << "Area: " << n.getArea() << std::endl;
            std::cout << "Perimeter: " << n.getPerimeter() << std::endl;
        }

        else if(work == "quit") {
            break;
        }
    }

    return 0;
}