#include <iostream>
#include <string>

#include "my_vector2.h"

using namespace std;

int main(void) {
    MyVector2 *v1 = nullptr, *v2 = nullptr;
    string a, b, c;
    int len;

    while(true) {
        cin >> a;

        if(a == "new") {
            cin >> len;
            v1 = new MyVector2(len);
            v2 = new MyVector2(len);
            cout << "Enter a\n";
            cin >> *v1;
            cout << "Enter b\n";
            cin >> *v2;
        }

        else if(a == "quit") {
            break;
        }

        else if(a == "a") {
            cin >> b >> c;

            if(b == "+") {
                if(c == "a") {
                    MyVector2 tmp(*v1 + *v1);
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyVector2 tmp(*v1 + *v2);
                    cout << tmp << endl;
                }

                else {
                    MyVector2 tmp(*v1 + stoi(c));
                    cout << tmp << endl;
                }
            }

            else if(b == "-") {
                if(c == "a") {
                    MyVector2 tmp(*v1 - *v1);
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyVector2 tmp(*v1 - *v2);
                    cout << tmp << endl;
                }

                else {
                    MyVector2 tmp(*v1 - stoi(c));
                    cout << tmp << endl;
                }
            }
        }

        else if(a == "b") {
            cin >> b >> c;

            if(b == "+") {
                if(c == "a") {
                    MyVector2 tmp(*v2 + *v1);
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyVector2 tmp(*v2 + *v2);
                    cout << tmp << endl;
                }

                else {
                    MyVector2 tmp(*v2 + stoi(c));
                    cout << tmp << endl;
                }
            }

            else if(b == "-") {
                if(c == "a") {
                    MyVector2 tmp(*v2 - *v1);
                    cout << tmp << endl;
                }

                else if(c == "b") {
                    MyVector2 tmp(*v2 - *v2);
                    cout << tmp << endl;
                }

                else {
                    MyVector2 tmp(*v2 - stoi(c));
                    cout << tmp << endl;
                }
            }
        }
    }

    return 0;
}