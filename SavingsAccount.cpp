#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

SavingsAccount::SavingsAccount(int id, string name, double balance, 
                               double interestRate, double minimumBalance)
    : Account(id, name, balance), interestRate(interestRate), minimumBalance(minimumBalance) {}

string SavingsAccount::getAccountType() const {
    return "Savings";
}

bool SavingsAccount::withdraw(double amount) {
    if (amount > 0 && (balance - amount) >= minimumBalance) {
        balance -= amount;
        return true;
    }
    return false;
}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}

void SavingsAccount::applyMonthlyOperations() {
    double interest = balance * interestRate / 12;  // Monthly interest
    balance += interest;
    cout << "Interest applied: $" << fixed << setprecision(2) << interest << endl;
}

void SavingsAccount::displayAccountInfo() const {
    Account::displayAccountInfo();
    cout << ", Interest Rate: " << fixed << setprecision(2) << (interestRate * 100) << "%"
         << ", Min Balance: $" << minimumBalance;
}

double SavingsAccount::getMinimumBalance() const {
    return minimumBalance;
}