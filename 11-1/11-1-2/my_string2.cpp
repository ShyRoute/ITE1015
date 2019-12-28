#include "my_string2.h"

#include <iostream>
#include <string>

MyString2::MyString2() {

}

MyString2::MyString2(std::string s) : str(s) {
    
}

MyString2::MyString2(const MyString2 &tmp) : str(tmp.str) {

}

MyString2 MyString2::operator+(const MyString2& b) {
    return MyString2(str + b.str);
}

MyString2 MyString2::operator*(const int b) {
    std::string tmp;
    for(int i = 0; i < b; i++) {
        tmp += str;
    }
    return MyString2(tmp);
}

std::ostream &operator<<(std::ostream &out, MyString2 &my_string) {
    out << my_string.str;
    return out;
}

std::istream &operator>>(std::istream &in, MyString2 &my_string) {
    in >> my_string.str;
    return in;
}
