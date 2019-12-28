#include "my_string2.h"

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string a, b, c;
    MyString2 s1, s2;

    while(true) {
        cin >> a;

        if(a == "new") {
            cout << "Enter a\n";
            cin >> s1;
            cout << "Enter b\n";
            cin >> s2;
        }

        else if(a == "quit") {
            break;
        }

        else if(a == "a") {
            cin >> b >> c;

            if(b == "+") {
                if(c == "a") {
                    MyString2 tmp(s1 + s1);
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyString2 tmp(s1 + s2);
                    cout << tmp << endl;
                }
            }

            else if(b == "*") {
                MyString2 tmp(s1 * stoi(c));
                cout << tmp << endl;
            }
        }

        else if(a == "b") {
            cin >> b >> c;

            if(b == "+") {
                if(c == "a") {
                    MyString2 tmp(s2 + s1);
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyString2 tmp(s2 + s2);
                    cout << tmp << endl;
                }
            }

            else if(b == "*") {
                MyString2 tmp(s2 * stoi(c));
                cout << tmp << endl;
            }
        }
    }

    return 0;
}