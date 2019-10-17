#include "setfunc.h"
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>

std::set<int> parseSet(const std::string &str) {
    std::set<int> result;
    std::string temp;
    std::stringstream check(str);

    while(std::getline(check, temp, ' ')) {
        result.insert(std::stoi(temp));
    }

    return result;
}

void printSet(const std::set<int> &set) {
    std::set<int>::iterator it;

    std::cout << "{ ";
    for(it = set.begin(); it != set.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;
}

std::set<int> getIntersection(const std::set<int> &set0, const std::set<int> &set1) {
    std::set<int> result;
    std::set<int>::iterator it0, it1;

    for(it0 = set0.begin(); it0 != set0.end(); it0++) {
        for(it1 = set1.begin(); it1 != set1.end(); it1++) {
            if(*it0 == *it1) {
                result.insert(*it0);
            }
        }
    }
    return result;
}

std::set<int> getUnion(const std::set<int> &set0, const std::set<int> &set1) {
    std::set<int> result;
    std::set<int>::iterator it0, it1;

    for(it0 = set0.begin(); it0 != set0.end(); it0++) result.insert(*it0);
    for(it1 = set1.begin(); it1 != set1.end(); it1++) result.insert(*it1);

    return result;
}

std::set<int> getDifference(const std::set<int> &set0, const std::set<int> &set1) {
    std::set<int> result;
    std::set<int>::iterator it0, it1;

    for(it0 = set0.begin(); it0 != set0.end(); it0++) result.insert(*it0);

    for(it1 = set1.begin(); it1 != set1.end(); it1++) {
        for(it0 = set0.begin(); it0 != set0.end(); it0++) {
            if(*it1 == *it0) result.erase(*it1);
        }
    }

    return result;
}