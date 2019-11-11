#include <iostream>
#include <string>
#include <vector>

class A {
    public:
    virtual std::string test() {
        return "A::test()\n";
    }
    virtual ~A() {

    }
};

class B : public A {
    public:
    virtual std::string test() {
        return "B::test()\n";
    }
    virtual ~B() {

    }
};

class C : public B {
    public:
    virtual std::string test() {
        return "C::test()\n";
    }
    virtual ~C() {

    }
};

int main(void) {
    A *obj1 = new A;
    B *obj2 = new B;
    C *obj3 = new C;

    std::vector<A *> arr;
    arr.push_back(obj1);
    arr.push_back(obj2);
    arr.push_back(obj3);

    for(std::vector<A *>::iterator it = arr.begin(); it != arr.end(); it++) {
        std::cout << (*it)->test();
    }

    for(std::vector<A *>::iterator it = arr.begin(); it != arr.end(); it++) {
        delete *it;
    }

    return 0;
}