#include "intset.h"
#include <iostream>
#include <vector>

int main(void) {
    IntegerSet numset;
    std::string input;
    std::vector<int> temp;
    int num;

    while(true) {
        std::cin >> input;
        if(input == "add") {
            std::cin >> num;
            numset.AddNumber(num);
            temp = numset.GetAll();
            for(int i = 0; i < temp.size(); i++) {
                std::cout << temp[i] << " ";
            }
            std::cout << std::endl;
        }

        else if(input == "del") {
            std::cin >> num;
            numset.DeleteNumber(num);
            temp = numset.GetAll();
            for(int i = 0; i < temp.size(); i++) {
                std::cout << temp[i] << " ";
            }
            std::cout << std::endl;
        }

        else if(input == "get") {
            std::cin >> num;
            std::cout << numset.GetItem(num) << std::endl;
        }

        else if(input == "quit") {
            break;
        }
    }
    return 0;
}