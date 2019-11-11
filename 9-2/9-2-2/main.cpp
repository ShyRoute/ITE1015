#include <iostream>
#include <string>
#include <vector>

#include "canvas.h"

using namespace std;

int main(void) {
    string work, shape;
    int w, h, a, b, x, y, cx, cy, tmp;
    char brush;
    vector<Shape *> shapeList;
    vector<Shape *>::iterator it;

    cin >> w >> h;
    Canvas canvas(w, h);
    canvas.Clear();
    canvas.Print();

    while(1) {
        cin >> work;

        if(work == "add") {
            cin >> shape;

            if(shape == "rect") {
                std::cin >> x >> y >> a >> b >> brush;
                shapeList.push_back(new Rectangle(x, y, a, b, brush));
            }

            else if(shape == "diamond") {
                std::cin >> x >> y >> a >> brush;
                shapeList.push_back(new Diamond(x, y, a, brush));
            }

            else if(shape == "tri_up") {
                std::cin >> x >> y >> a >> brush;
                shapeList.push_back(new UpTriangle(x, y, a, brush));
            }

            else if(shape == "tri_down") {
                std::cin >> x >> y >> a >> brush;
                shapeList.push_back(new DownTriangle(x, y, a, brush));
            }
        }

        else if(work == "delete") {
            cin >> tmp;
            if(tmp < shapeList.size()) {
                it = shapeList.begin() + tmp;
                delete *it;

                shapeList.erase(it);
            }
        }

        else if(work == "draw") {
            canvas.Clear();

            for(it = shapeList.begin(); it != shapeList.end(); it++) {
                (*it)->Draw(&canvas);
            }

            canvas.Print();
        }

        else if(work == "dump") {
            int i = 0;
            for(it = shapeList.begin(); it != shapeList.end(); it++) {
                cout << i++ << ' ';
                (*it)->printInfo();
            }
        }

        else if(work == "resize") {
            cin >> w >> h;
            canvas.Resize(w, h);

            for(it = shapeList.begin(); it != shapeList.end(); it++) {
                (*it)->Draw(&canvas);
            }
        }

        else if(work == "quit") {
            break;
        }
    }

    for(it = shapeList.begin(); it != shapeList.end(); it++) {
        delete *it;
    }

    return 0;
}