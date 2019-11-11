#include <iostream>
#include <string>
#include <vector>

class A {
    public:
    A();
    A(int n) {
        memberA = new int;
        *memberA = n;
        std::cout << "new memberA\n";
    }

    virtual ~A() {
        delete memberA;
        std::cout << "delete memberA\n";
    }

    virtual void print() {
        std::cout << "*memberA " << *memberA << '\n';
    }

    private:
    int *memberA;
};

class B : public A {
    public:
    B();
    B(double n) : A(1) {
        memberB = new double;
        *memberB = n;
        std::cout << "new memberB\n";
    }

    virtual ~B() {
        delete memberB;
        std::cout << "delete memberB\n";
    }

    virtual void print() {
        A::print();
        std::cout << "*memberB " << *memberB << '\n';
    }

    private:
    double *memberB;
};

class C : public B {
    public:
    C();
    C(const std::string &n) : B(1.1) {
        memberC = new std::string;
        *memberC = n;
        std::cout << "new memberC\n";
    }

    virtual ~C() {
        delete memberC;
        std::cout << "delete memberC\n";
    }

    virtual void print() {
        B::print();
        std::cout << "*memberC " << *memberC << '\n';
    }

    private:
    std::string *memberC;
};

int main(void) {
    int n1;
    double n2;
    std::string n3;

    std::cin >> n1 >> n2 >> n3;

    A *obj1 = new A(n1);
    B *obj2 = new B(n2);
    C *obj3 = new C(n3);

    std::vector<A *> arr;
    arr.push_back(obj1);
    arr.push_back(obj2);
    arr.push_back(obj3);

    for(std::vector<A *>::iterator it = arr.begin(); it != arr.end(); it++) {
        (*it)->print();
    }

    for(std::vector<A *>::iterator it = arr.begin(); it != arr.end(); it++) {
        delete *it;
    }

    return 0;
}