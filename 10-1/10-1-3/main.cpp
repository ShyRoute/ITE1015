#include <iostream>
#include <vector>
#include <string>

class B {
    public:
    virtual ~B() {
    }
};

class C : public B {
    public:
    void test_C() {
        std::cout << "C::test_C()" << std::endl;
    }
};

class D : public B {
    public:
    void test_D() {
        std::cout << "D::test_D()" << std::endl;
    }
};

int main(void) {
    std::string work;
    std::vector<B *> arr;
    std::vector<B *>::iterator it;

    while(true) {
        std::cin >> work;

        if(work == "B") {
            arr.push_back(new B);
        }

        else if(work == "C") {
            arr.push_back(new C);
        }

        else if(work == "D") {
            arr.push_back(new D);
        }

        else if(work == "0") {
            break;
        }
    }

    for(it = arr.begin(); it != arr.end(); it++) {
        C *tmp = dynamic_cast<C *>(*it);
        if(tmp) {
            tmp->test_C();
        }

        D *tmp2 = dynamic_cast<D *>(*it);
        if(tmp2) {
            tmp2->test_D();
        }
    }

    for(it = arr.begin(); it != arr.end(); it++) {
        delete *it;
    }

    return 0;
}