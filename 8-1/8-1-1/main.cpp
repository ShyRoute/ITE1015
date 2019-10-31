#include <iostream>
#include <string>
#include "number.h"

int main(void) {
    int num;
    std::string work;

    while(true) {
        std::cin >> work;

        if(work == "number") {
            std::cin >> num;
            Number n;
            n.setNumber(num);

            std::cout << "getNumber(): " << n.getNumber() << std::endl;
        }

        else if(work == "square") {
            std::cin >> num;
            Square n;
            n.setNumber(num);

            std::cout << "getNumber(): " << n.getNumber() << std::endl;
            std::cout << "getSquare(): " << n.getSquare() << std::endl;
        }

        else if(work == "cube") {
            std::cin >> num;
            Cube n;
            n.setNumber(num);

            std::cout << "getNumber(): " << n.getNumber() << std::endl;
            std::cout << "getSquare(): " << n.getSquare() << std::endl;
            std::cout << "getCube(): " << n.getCube() << std::endl;
        }

        else if(work == "quit") {
            break;
        }
    }
    
    return 0;
}