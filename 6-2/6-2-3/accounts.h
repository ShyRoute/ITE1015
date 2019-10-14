#ifndef __account__
#define __account__

#include <iostream>

class Account {
    private:
    int id;
    int deposit;

    public:
    void setAccount(int _id, int _deposit);
    void setDeposit(int _deposit);
    int getID();
    int getDeposit();
    void displayAccount();
};

class AccountManager {
    private:
    Account accounts[10];
    int accountsNumber;

    public:
    AccountManager();

    void newAccount(AccountManager *manager);
    void deposit(int _id, int _amount);
    void withdraw(int _id, int _amount);
    void transfer(int _from, int _to, int amount);
    bool checkBalance(int _balance);
    bool checkID(int _id);
};
#endif