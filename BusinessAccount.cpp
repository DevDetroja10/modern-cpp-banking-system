#include "BusinessAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

BusinessAccount::BusinessAccount(int id, string name, double balance, 
                                 double transactionFee, int freeTransactionLimit)
    : Account(id, name, balance), transactionFee(transactionFee), 
      freeTransactionLimit(freeTransactionLimit), transactionCount(0) {}

string BusinessAccount::getAccountType() const {
    return "Business";
}

bool BusinessAccount::withdraw(double amount) {
    double totalAmount = amount;
    if (transactionCount >= freeTransactionLimit) {
        totalAmount += transactionFee;
    }
    
    if (totalAmount > 0 && totalAmount <= balance) {
        balance -= totalAmount;
        transactionCount++;
        if (transactionCount > freeTransactionLimit) {
            cout << "Transaction fee applied: $" << fixed << setprecision(2) << transactionFee << endl;
        }
        return true;
    }
    return false;
}

void BusinessAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactionCount++;
        if (transactionCount > freeTransactionLimit) {
            balance -= transactionFee;
            cout << "Transaction fee applied: $" << fixed << setprecision(2) << transactionFee << endl;
        }
    }
}

void BusinessAccount::applyMonthlyOperations() {
    transactionCount = 0;  // Reset transaction count
    cout << "Transaction count reset for new month." << endl;
}

void BusinessAccount::displayAccountInfo() const {
    Account::displayAccountInfo();
    cout << ", Transaction Fee: $" << transactionFee
         << ", Free Transactions: " << freeTransactionLimit
         << ", Used Transactions: " << transactionCount;
}

double BusinessAccount::getTransactionFee() const {
    return transactionFee;
}

int BusinessAccount::getFreeTransactionLimit() const {
    return freeTransactionLimit;
}

int BusinessAccount::getTransactionCount() const {
    return transactionCount;
}

void BusinessAccount::setTransactionCount(int count) {
    transactionCount = count;
}