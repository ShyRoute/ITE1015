#include "my_vector2.h"

MyVector2::MyVector2() : length(0), a(NULL) {
}

MyVector2::MyVector2(int length) : length(length), a(new double[length]) {
}

MyVector2::MyVector2(const MyVector2 &mv) : length(mv.length), a(new double[mv.length]) {
    for(int i = 0; i < mv.length; ++i) {
        a[i] = mv.a[i];
    }
}

MyVector2::~MyVector2() {
    delete[] a;
}

MyVector2 MyVector2::operator+(const MyVector2 &b) {
    MyVector2 tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] + b.a[i];
    }
    return tmp;
}

MyVector2 MyVector2::operator-(const MyVector2 &b) {
    MyVector2 tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] - b.a[i];
    }
    return tmp;
}

MyVector2 MyVector2::operator+(const int b) {
    MyVector2 tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] + b;
    }
    return tmp;
}

MyVector2 MyVector2::operator-(const int b) {
    MyVector2 tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] - b;
    }
    return tmp;
}

std::ostream &operator<<(std::ostream &out, MyVector2 &b) {
    for(int i = 0; i < b.length; ++i) {
        out << b.a[i] << ' ';
    }
    return out;
}

std::istream &operator>>(std::istream &in, MyVector2 &b) {
    for(int i = 0; i < b.length; ++i) {
        in >> b.a[i];
    }
    return in;
}
