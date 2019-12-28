#include "my_string.h"

#include <iostream>
#include <sstream>

MyString &MyString::operator=(const MyString &b) {
    str = b.str;
    return *this;
}

MyString MyString::operator+(const MyString &b) {
    MyString tmp;
    tmp.str = str + b.str;
    return tmp;
}

MyString MyString::operator*(const int b) {
    MyString tmp;
    for(int i = 0; i < b; i++) {
        tmp.str += str;
    }
    return tmp;
}

std::ostream &operator<<(std::ostream &out, MyString &my_string) {
    out << my_string.str;
    return out;
}

std::istream &operator>>(std::istream &in, MyString &my_string) {
    in >> my_string.str;
    return in;
}
