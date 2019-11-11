#include <iostream>

#include "animal.h"

Animal::Animal(std::string name, int age) {
    _name = name;
    _age = age;
}

void Animal::printInfo() {

}

Zebra::Zebra(std::string name, int age, int numStripes) : Animal(name, age) {
    _numStripes = numStripes;
}

void Zebra::printInfo() {
    std::cout << "Zebra, Name: " << _name << ", Age: " << _age << ", Number of stripes: " << _numStripes << std::endl;
}

Cat::Cat(std::string name, int age, std::string favoriteToy) : Animal(name, age) {
    _favoriteToy = favoriteToy;
}

void Cat::printInfo() {
    std::cout << "Cat, Name: " << _name << ", Age: " << _age << ", Favorite toy: " << _favoriteToy << std::endl;
}