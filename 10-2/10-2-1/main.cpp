#include <iostream>
#include <vector>

#include "clocks.h"

using namespace std;

int main(void) {
    vector<Clock *> clockList;
    vector<Clock *>::iterator it;
    clockList.push_back(new SundialClock(0, 0, 0));
    clockList.push_back(new CuckooClock(0, 0, 0));
    clockList.push_back(new GrandFatherClock(0, 0, 0));
    clockList.push_back(new WristClock(0, 0, 0));
    clockList.push_back(new AtomicClock(0, 0, 0));

    for(it = clockList.begin(); it != clockList.end(); ++it) {
        (*it)->reset();
    }

    int runTime;

    cin >> runTime;

    cout << "\nReported clock times after resetting:\n";

    for(it = clockList.begin(); it != clockList.end(); ++it) {
        (*it)->displayTime();
    }

    cout << "\nRunning the clocks...\n";

    for(it = clockList.begin(); it != clockList.end(); ++it) {
        for(int i = 0; i < runTime; i++) {
            (*it)->tick();
        }
    }

    cout << "\nReported clock times after running:\n";

    for(it = clockList.begin(); it != clockList.end(); ++it) {
        (*it)->displayTime();
    }


    for(it = clockList.begin(); it != clockList.end(); ++it) {
        delete *it;
    }

    return 0;
}