#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "BusinessAccount.h"
using namespace std;

class Bank {
public:
    void addSavingsAccount(int id, string name, double balance, 
                           double interestRate = 0.02, double minimumBalance = 100.0);
    void addCheckingAccount(int id, string name, double balance, 
                            double overdraftLimit = 500.0, double monthlyFee = 10.0);
    void addBusinessAccount(int id, string name, double balance, 
                            double transactionFee = 2.0, int freeTransactionLimit = 50);
    
    int findAccountIndex(int id);
    bool deposit(int id, double amount);
    bool withdraw(int id, double amount);
    void displayAllAccounts() const;
    void applyMonthlyOperationsToAll();
    const vector<Account>& getAllAccounts() const;
    
    // FUNCTION OVERLOADING - Find function with different parameters
    void findAccount(int id) const;           // Find by ID
    void findAccount(string name) const;      // Find by name
    
    // New methods for FileManager access
    const vector<SavingsAccount>& getSavingsAccounts() const;
    const vector<CheckingAccount>& getCheckingAccounts() const;
    const vector<BusinessAccount>& getBusinessAccounts() const;
    void clearAllAccounts();

private:
    vector<SavingsAccount> savingsAccounts;
    vector<CheckingAccount> checkingAccounts;
    vector<BusinessAccount> businessAccounts;
};

#endif