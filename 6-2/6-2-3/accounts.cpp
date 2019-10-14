#include <iostream>
#include "accounts.h"

void Account::setAccount(int _id, int _deposit) {
    id = _id;
    deposit = _deposit;
}

void Account::setDeposit(int _deposit) {
    deposit = _deposit;
}

int Account::getID() {
    return id;
}

int Account::getDeposit() {
    return deposit;
}

void Account::displayAccount() {
    std::cout << "Balance of user " << id << ": " << deposit << "\n\n";
}

AccountManager::AccountManager() {
    accountsNumber = 0;
}

void AccountManager::newAccount(AccountManager *manager) {
    if(accountsNumber == 10) {
        std::cout << "Cannot create more than 10 accounts\n\n";
        return;
    }

    int n = accountsNumber;
    manager->accounts[n].setAccount(n, 0);
    accountsNumber++;
    std::cout << "Account for user " << n << " registered\n";
    accounts[n].displayAccount();
}

void AccountManager::deposit(int _id, int _amount) {
    Account temp = accounts[_id];

    if(!checkID(temp.getID())) {
        std::cout << "Account does not exist\n\n";
        return;
    }
    
    int balance = temp.getDeposit();
    balance += _amount;
    if(checkBalance(balance)) {
        accounts[_id].setDeposit(balance);
        accounts[_id].displayAccount();
    }
    else {
        std::cout << "Cannot deposit more than 1,000,000 won\n";
        accounts[_id].displayAccount();
    }
}

void AccountManager::withdraw(int _id, int _amount) {
    Account temp = accounts[_id];

    if(!checkID(temp.getID())) {
        std::cout << "Account does not exist\n\n";
        return;
    }

    int balance = temp.getDeposit();
    balance -= _amount;
    if(checkBalance(balance)) {
        accounts[_id].setDeposit(balance);
        accounts[_id].displayAccount();
    }
    else{
        std::cout << "Cannot withdraw more than you've deposited\n";
        accounts[_id].displayAccount();
    }
}

void AccountManager::transfer(int _from, int _to, int amount) {
    Account from = accounts[_from];
    Account to = accounts[_to];

    if(!checkID(from.getID()) || !checkID(to.getID())) {
        std::cout << "Account does not exist\n\n";
        return;
    }

    int fromBalance = from.getDeposit();
    int toBalance = to.getDeposit();

    fromBalance -= amount;
    if(checkBalance(fromBalance)){
        accounts[_from].setDeposit(fromBalance);
        accounts[_from].displayAccount();
    }
    else {
        std::cout << "Cannot withdraw more than you've deposited\n";
        if(_from < _to){
            accounts[_from].displayAccount();
            accounts[_to].displayAccount();
        }
        else{
            accounts[_to].displayAccount();
            accounts[_from].displayAccount();
        }
        return;
    }

    toBalance += amount;
    if(checkBalance(toBalance)) {
        accounts[_to].setDeposit(toBalance);
        accounts[_to].displayAccount();
    }
    else {
        std::cout << "Cannot deposit more than 1,000,000 won\n";
        if(_from < _to){
            accounts[_from].displayAccount();
            accounts[_to].displayAccount();
        }
        else{
            accounts[_to].displayAccount();
            accounts[_from].displayAccount();
        }
        return;
    }
}

bool AccountManager::checkBalance(int _balance) {
    if(_balance >= 1000000 || _balance < 0) return false;
    else return true;
}

bool AccountManager::checkID(int _id) {
    if(_id >= accountsNumber) return false;
    else return true;
}