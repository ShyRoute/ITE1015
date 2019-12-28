#include "my_vector.h"

MyVector::MyVector() : length(0), a(NULL) {
}

MyVector::MyVector(int length) : length(length), a(new double[length]) {
}

MyVector::~MyVector() {
    delete[] a;
}

MyVector &MyVector::operator=(const MyVector &b) {
    length = b.length;
    delete[] a;
    a = new double[length];
    for(int i = 0; i < b.length; ++i) {
        a[i] = b.a[i];
    }
    return *this;
}

MyVector MyVector::operator+(const MyVector &b) {
    MyVector tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] + b.a[i];
    }
    return tmp;
}

MyVector MyVector::operator-(const MyVector &b) {
    MyVector tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] - b.a[i];
    }
    return tmp;
}

MyVector MyVector::operator+(const int b) {
    MyVector tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] + b;
    }
    return tmp;
}

MyVector MyVector::operator-(const int b) {
    MyVector tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] - b;
    }
    return tmp;
}

std::ostream &operator<<(std::ostream &out, const MyVector &b) {
    for(int i = 0; i < b.length; ++i) {
        out << b.a[i] << ' ';
    }
    return out;
}

std::istream &operator>>(std::istream &in, MyVector &b) {
    for(int i = 0; i < b.length; ++i) {
        in >> b.a[i];
    }
    return in;
}