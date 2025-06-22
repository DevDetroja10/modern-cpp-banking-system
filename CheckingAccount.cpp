#include "CheckingAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

CheckingAccount::CheckingAccount(int id, string name, double balance, 
                                 double overdraftLimit, double monthlyFee)
    : Account(id, name, balance), overdraftLimit(overdraftLimit), 
      monthlyFee(monthlyFee), transactionCount(0) {}

string CheckingAccount::getAccountType() const {
    return "Checking";
}

bool CheckingAccount::withdraw(double amount) {
    if (amount > 0 && (balance - amount) >= -overdraftLimit) {
        balance -= amount;
        transactionCount++;
        return true;
    }
    return false;
}

void CheckingAccount::deposit(double amount) {
    Account::deposit(amount);
    if (amount > 0) {
        transactionCount++;
    }
}

void CheckingAccount::applyMonthlyOperations() {
    balance -= monthlyFee;
    cout << "Monthly fee applied: $" << fixed << setprecision(2) << monthlyFee << endl;
    transactionCount = 0;  // Reset transaction count
}

void CheckingAccount::displayAccountInfo() const {
    Account::displayAccountInfo();
    cout << ", Overdraft Limit: $" << overdraftLimit
         << ", Monthly Fee: $" << monthlyFee
         << ", Transactions: " << transactionCount;
}

int CheckingAccount::getTransactionCount() const {
    return transactionCount;
}

double CheckingAccount::getOverdraftLimit() const {
    return overdraftLimit;
}

double CheckingAccount::getMonthlyFee() const {
    return monthlyFee;
}

void CheckingAccount::setTransactionCount(int count) {
    transactionCount = count;
}