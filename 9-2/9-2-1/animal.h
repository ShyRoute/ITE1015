#pragma once
#include <iostream>
#include <string>

class Animal {
    public:
    Animal(std::string name, int age);
    virtual void printInfo();

    protected:
    std::string _name;
    int _age;
};

class Zebra : public Animal {
    public:
    Zebra(std::string name, int age, int numStripes);
    virtual void printInfo();

    private:
    int _numStripes;
};

class Cat : public Animal {
    public:
    Cat(std::string name, int age, std::string favoriteToy);
    virtual void printInfo();

    private:
    std::string _favoriteToy;
};