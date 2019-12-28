#include <iostream>
#include <string>

using namespace std;

template <typename T>
void myswap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main(void) {
    int a1, a2;
    double b1, b2;
    string c1, c2;

    cin >> a1 >> a2;
    myswap(a1, a2);
    cout << "After calling myswap(): " << a1 << ' ' << a2 << endl;

    cin >> b1 >> b2;
    myswap(b1, b2);
    cout << "After calling myswap(): " << b1 << ' ' << b2 << endl;

    cin >> c1 >> c2;
    myswap(c1, c2);
    cout << "After calling myswap(): " << c1 << ' ' << c2 << endl;

    return 0;
}