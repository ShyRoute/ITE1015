#include "setfunc.h"
#include <iostream>
#include <set>
#include <string>

int main(void) {
    std::set<int> s0, s1;
    std::string input, num0, num1;
    int range;

    while(true) {
        std::getline(std::cin, input);

        if(input == "0") break;

        range = input.find('}') + 2;

        if(input[range] == '+') {
            num0 = input.substr(2, range - 5);
            num1 = input.substr(range + 4, input.size() - range - 6);
            s0 = parseSet(num0);
            s1 = parseSet(num1);
            printSet(getUnion(s0, s1));
        }

        else if(input[range] == '-') {
            num0 = input.substr(2, range - 5);
            num1 = input.substr(range + 4, input.size() - range - 6);
            s0 = parseSet(num0);
            s1 = parseSet(num1);
            printSet(getDifference(s0, s1));
        }

        else if(input[range] == '*') {
            num0 = input.substr(2, range - 5);
            num1 = input.substr(range + 4, input.size() - range - 6);
            s0 = parseSet(num0);
            s1 = parseSet(num1);
            printSet(getIntersection(s0, s1));
        }
    }
    return 0;
}