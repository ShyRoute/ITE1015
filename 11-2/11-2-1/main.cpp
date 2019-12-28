#include "my_vector.h"

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    MyVector v1, v2;
    string a, b, c;
    int len;

    while(true) {
        cin >> a;

        if(a == "new") {
            cin >> len;
            MyVector t1(len), t2(len);
            cout << "Enter a\n";
            cin >> t1;
            v1 = t1;
            cout << "Enter b\n";
            cin >> t2;
            v2 = t2;
        }

        else if(a == "quit") {
            break;
        }

        else if(a == "a") {
            cin >> b >> c;

            if(b == "+") {
                if(c == "a") {
                    MyVector tmp = v1 + v1;
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyVector tmp = v1 + v2;
                    cout << tmp << endl;
                }

                else {
                    MyVector tmp = v1 + stoi(c);
                    cout << tmp << endl;
                }
            }

            else if(b == "-") {
                if(c == "a") {
                    MyVector tmp = v1 - v1;
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyVector tmp = v1 - v2;
                    cout << tmp << endl;
                }

                else {
                    MyVector tmp = v1 - stoi(c);
                    cout << tmp << endl;
                }
            }
        }

        else if(a == "b") {
            cin >> b >> c;

            if(b == "+") {
                if(c == "a") {
                    MyVector tmp = v2 + v1;
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyVector tmp = v2 + v2;
                    cout << tmp << endl;
                }

                else {
                    MyVector tmp = v2 + stoi(c);
                    cout << tmp << endl;
                }
            }

            else if(b == "-") {
                if(c == "a") {
                    MyVector tmp = v2 - v1;
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyVector tmp = v2 - v2;
                    cout << tmp << endl;
                }

                else {
                    MyVector tmp = v2 - stoi(c);
                    cout << tmp << endl;
                }
            }
        }
    }

    return 0;
}