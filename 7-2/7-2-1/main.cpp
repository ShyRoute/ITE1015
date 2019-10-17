#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "message.h"

int main(void) {
    MessageBook book;
    std::string input, msg;
    char temp;
    int number;

    while(true) {
        std::cin >> input;

        if(input == "add") {
            std::cin >> number;
            std::cin.ignore(1);
            std::getline(std::cin, msg);
            book.AddMessage(number, msg);
        }

        else if(input == "delete") {
            std::cin >> number;
            book.DeleteMessage(number);
        }

        else if(input == "print") {
            std::cin >> number;
            msg = book.GetMessage(number);
            std::cout << msg << std::endl;
        }

        else if(input == "list") {
            std::vector<int> numList = book.GetNumbers();
            for(int i = 0; i < numList.size(); i++) {
                msg = book.GetMessage(numList[i]);
                std::cout << numList[i] << ": " << msg << std::endl;
            }
        }

        else if(input == "quit") {
            break;
        }
    }
    return 0;
}