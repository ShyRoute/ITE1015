#include <iostream>
#include <string>

#include "my_container.h"

using namespace std;

int main(void) {
    int n1, n2, n3;

    cin >> n1;
    MyContainer<int> c1(n1);
    cin >> c1;
    cout << c1 << endl;

    cin >> n2;
    MyContainer<double> c2(n2);
    cin >> c2;
    cout << c2 << endl;

    cin >> n3;
    MyContainer<string> c3(n3);
    cin >> c3;
    cout << c3 << endl;

    return 0;
}