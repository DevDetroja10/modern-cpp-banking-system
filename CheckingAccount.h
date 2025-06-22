#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"
using namespace std;

class CheckingAccount : public Account {
private:
    double overdraftLimit;
    double monthlyFee;
    int transactionCount;

public:
    CheckingAccount(int id, string name, double balance, 
                    double overdraftLimit = 500.0, double monthlyFee = 10.0);
    
    string getAccountType() const override;
    bool withdraw(double amount) override;
    void deposit(double amount) override;
    void applyMonthlyOperations() override;
    void displayAccountInfo() const override;
    int getTransactionCount() const;
    
    // Additional getters and setters for FileManager
    double getOverdraftLimit() const;
    double getMonthlyFee() const;
    void setTransactionCount(int count);
};

#endif