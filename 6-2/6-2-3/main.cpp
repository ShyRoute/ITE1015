#include <iostream>
#include "accounts.h"

int main(void) {
    char command;
    bool check = false;
    int id, amount, from, to;

    AccountManager manager;

    while(true) {
        std::cout << "Job?\n";
        std::cin >> command;

        switch(command) {
            case 'N':
                manager.newAccount(&manager);
                break;

            case 'D':
                std::cin >> id >> amount;
                manager.deposit(id, amount);
                break;

            case 'W':
                std::cin >> id >> amount;
                manager.withdraw(id, amount);
                break;

            case 'T':
                std::cin >> from >> to >> amount;
                manager.transfer(from, to, amount);
                break;

            case 'Q':
                check = true;
                break;
        }

        if(check) break;

    }

    return 0;
}    