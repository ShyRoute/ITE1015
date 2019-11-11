#include <iostream>
#include <string>
#include <vector>

class A {
    public:
    virtual std::string getTypeInfo() {
        return "This is an instance of class A\n";
    }
    virtual ~A() {

    }
};

class B : public A {
    public:
    virtual std::string getTypeInfo() {
        return "This is an instance of class B\n";
    }
    virtual ~B() {

    }
};

class C : public B {
    public:
    virtual std::string getTypeInfo() {
        return "This is an instance of class C\n";
    }
    virtual ~C() {

    }
};

void printObjectTypeInfo1(A *object) {
    std::cout << object->getTypeInfo();
}

void printObjectTypeInfo2(A &object) {
    std::cout << object.getTypeInfo();
}

int main(void) {
    A *obj1 = new A;
    B *obj2 = new B;
    C *obj3 = new C;

    std::vector<A *> arr;
    arr.push_back(obj1);
    arr.push_back(obj2);
    arr.push_back(obj3);

    for(std::vector<A *>::iterator it = arr.begin(); it != arr.end(); it++) {
        printObjectTypeInfo1(*it);
        printObjectTypeInfo2(**it);
    }

    for(std::vector<A *>::iterator it = arr.begin(); it != arr.end(); it++) {
        delete *it;
    }

    return 0;
}