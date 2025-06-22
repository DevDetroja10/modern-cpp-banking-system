#include "Bank.h"
#include <iostream>
using namespace std;

void Bank::addSavingsAccount(int id, string name, double balance, 
                             double interestRate, double minimumBalance) {
    savingsAccounts.emplace_back(id, name, balance, interestRate, minimumBalance);
}

void Bank::addCheckingAccount(int id, string name, double balance, 
                              double overdraftLimit, double monthlyFee) {
    checkingAccounts.emplace_back(id, name, balance, overdraftLimit, monthlyFee);
}

void Bank::addBusinessAccount(int id, string name, double balance, 
                              double transactionFee, int freeTransactionLimit) {
    businessAccounts.emplace_back(id, name, balance, transactionFee, freeTransactionLimit);
}

int Bank::findAccountIndex(int id) {
    // Check savings accounts
    for (int i = 0; i < savingsAccounts.size(); i++) {
        if (savingsAccounts[i].getId() == id) {
            return i;
        }
    }
    return -1;  // Simplified for this example
}

bool Bank::deposit(int id, double amount) {
    // Check in savings accounts
    for (auto& acc : savingsAccounts) {
        if (acc.getId() == id) {
            acc.deposit(amount);
            return true;
        }
    }
    
    // Check in checking accounts
    for (auto& acc : checkingAccounts) {
        if (acc.getId() == id) {
            acc.deposit(amount);
            return true;
        }
    }
    
    // Check in business accounts
    for (auto& acc : businessAccounts) {
        if (acc.getId() == id) {
            acc.deposit(amount);
            return true;
        }
    }
    
    return false;
}

bool Bank::withdraw(int id, double amount) {
    // Check in savings accounts
    for (auto& acc : savingsAccounts) {
        if (acc.getId() == id) {
            return acc.withdraw(amount);
        }
    }
    
    // Check in checking accounts
    for (auto& acc : checkingAccounts) {
        if (acc.getId() == id) {
            return acc.withdraw(amount);
        }
    }
    
    // Check in business accounts
    for (auto& acc : businessAccounts) {
        if (acc.getId() == id) {
            return acc.withdraw(amount);
        }
    }
    
    return false;
}

void Bank::displayAllAccounts() const {
    cout << "\n=== All Accounts ===" << endl;
    cout << "-------------------" << endl;
    
    cout << "\nSavings Accounts:" << endl;
    for (const auto& acc : savingsAccounts) {
        acc.displayAccountInfo();
        cout << endl;
    }
    
    cout << "\nChecking Accounts:" << endl;
    for (const auto& acc : checkingAccounts) {
        acc.displayAccountInfo();
        cout << endl;
    }
    
    cout << "\nBusiness Accounts:" << endl;
    for (const auto& acc : businessAccounts) {
        acc.displayAccountInfo();
        cout << endl;
    }
}

void Bank::applyMonthlyOperationsToAll() {
    cout << "\n=== Applying Monthly Operations ===" << endl;
    
    cout << "\nSavings Accounts:" << endl;
    for (auto& acc : savingsAccounts) {
        cout << "Account " << acc.getId() << ": ";
        acc.applyMonthlyOperations();
    }
    
    cout << "\nChecking Accounts:" << endl;
    for (auto& acc : checkingAccounts) {
        cout << "Account " << acc.getId() << ": ";
        acc.applyMonthlyOperations();
    }
    
    cout << "\nBusiness Accounts:" << endl;
    for (auto& acc : businessAccounts) {
        cout << "Account " << acc.getId() << ": ";
        acc.applyMonthlyOperations();
    }
}

// FUNCTION OVERLOADING IMPLEMENTATIONS

// Find account by ID
void Bank::findAccount(int id) const {
    cout << "\n=== Search Result for ID: " << id << " ===" << endl;
    bool found = false;
    
    // Search in savings accounts
    for (const auto& acc : savingsAccounts) {
        if (acc.getId() == id) {
            acc.displayAccountInfo();
            cout << endl;
            found = true;
            break;
        }
    }
    
    // Search in checking accounts
    if (!found) {
        for (const auto& acc : checkingAccounts) {
            if (acc.getId() == id) {
                acc.displayAccountInfo();
                cout << endl;
                found = true;
                break;
            }
        }
    }
    
    // Search in business accounts
    if (!found) {
        for (const auto& acc : businessAccounts) {
            if (acc.getId() == id) {
                acc.displayAccountInfo();
                cout << endl;
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "Account with ID " << id << " not found!" << endl;
    }
}

// Find account by name
void Bank::findAccount(string name) const {
    cout << "\n=== Search Result for Name: " << name << " ===" << endl;
    bool found = false;
    
    // Search in savings accounts
    for (const auto& acc : savingsAccounts) {
        if (acc.getName() == name) {
            acc.displayAccountInfo();
            cout << endl;
            found = true;
        }
    }
    
    // Search in checking accounts
    for (const auto& acc : checkingAccounts) {
        if (acc.getName() == name) {
            acc.displayAccountInfo();
            cout << endl;
            found = true;
        }
    }
    
    // Search in business accounts
    for (const auto& acc : businessAccounts) {
        if (acc.getName() == name) {
            acc.displayAccountInfo();
            cout << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Account with name " << name << " not found!" << endl;
    }
}

// For compatibility with existing FileManager
const vector<Account>& Bank::getAllAccounts() const {
    static vector<Account> empty;
    return empty;  // FileManager would need updating for new structure
}

// New methods for FileManager access
const vector<SavingsAccount>& Bank::getSavingsAccounts() const {
    return savingsAccounts;
}

const vector<CheckingAccount>& Bank::getCheckingAccounts() const {
    return checkingAccounts;
}

const vector<BusinessAccount>& Bank::getBusinessAccounts() const {
    return businessAccounts;
}

void Bank::clearAllAccounts() {
    savingsAccounts.clear();
    checkingAccounts.clear();
    businessAccounts.clear();
}