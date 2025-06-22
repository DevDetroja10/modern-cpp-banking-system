#include "Account.h"
#include <iostream>
#include <iomanip>
using namespace std;

Account::Account(int id, string name, double balance)
    : id(id), name(name), balance(balance) {}

int Account::getId() const { 
    return id; 
}

string Account::getName() const { 
    return name; 
}

double Account::getBalance() const { 
    return balance; 
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::displayAccountInfo() const {
    cout << "ID: " << id 
         << ", Name: " << name 
         << ", Type: " << getAccountType()
         << ", Balance: $" << fixed << setprecision(2) << balance;
}