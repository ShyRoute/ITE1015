#include <iostream>
#include <string>
#include "sorted.h"

int main(void) {
    SortedArray arr;
    std::string input, temp;
    int num;

    while(true) {
        std::cin >> input;
        if(input[0] >= '0' && input[0] <= '9') {
            arr.AddNumber(std::stoi(input));
        }
        else {
            if(input == "ascend") {
                std::vector<int> sorted = arr.GetSortedAscending();
                for(int i = 0; i < (int)sorted.size(); i++) {
                    std::cout << sorted[i] << " ";
                }
                std::cout << std::endl;
            }
            else if(input == "descend") {
                std::vector<int> sorted = arr.GetSortedDescending();
                for(int i = 0; i < (int)sorted.size(); i++) {
                    std::cout << sorted[i] << " ";
                }
                std::cout << std::endl;
            }
            else if(input == "max") {
                num = arr.GetMax();
                std::cout << num << std::endl;
            }
            else if(input == "min") {
                num = arr.GetMin();
                std::cout << num << std::endl;
            }
            else if(input == "quit") {
                break;
            }
        }
    }
    return 0;
}