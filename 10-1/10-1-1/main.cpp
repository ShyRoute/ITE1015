#include <iostream>
#include <vector>
#include <string>

#include "shape.h"

using namespace std;

int main(void) {
    string work;
    double w, h;
    vector<Shape *> arr;
    vector<Shape *>::iterator it;

    while(true) {
        cin >> work;

        if(work == "r") {
            cin >> w >> h;
            arr.push_back(new Rectangle(w, h));
        }

        else if(work == "t") {
            cin >> w >> h;
            arr.push_back(new Triangle(w, h));
        }

        else if(work == "0") {
            break;
        }
    }

    for(it = arr.begin(); it != arr.end(); it++) {
        cout << (*it)->getArea() << '\n';
    }

    for(it = arr.begin(); it != arr.end(); it++) {
        delete *it;
    }

    return 0;
}