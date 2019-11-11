#include <iostream>
#include <string>
#include <vector>

#include "animal.h"

int main(void) {
    std::vector<Animal *> animals;
    std::vector<Animal *>::iterator it;
    char work;
    int age, tmp1;
    std::string name, tmp2;

    while(1) {
        std::cin >> work;

        if(work == 'z') {
            std::cin >> name >> age >> tmp1;
            animals.push_back(new Zebra(name, age, tmp1));
        }

        else if(work == 'c') {
            std::cin >> name >> age >> tmp2;
            animals.push_back(new Cat(name, age, tmp2));
        }

        else if(work == '0') {
            break;
        }
    }

    for(it = animals.begin(); it != animals.end(); it++) {
        (*it)->printInfo();
    }

    for(it = animals.begin(); it != animals.end(); it++) {
        delete *it;
    }

    return 0;
}