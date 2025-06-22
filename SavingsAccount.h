#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"
using namespace std;

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int id, string name, double balance, 
                   double interestRate = 0.02, double minimumBalance = 100.0);
    
    string getAccountType() const override;
    bool withdraw(double amount) override;
    double getInterestRate() const override;
    void applyMonthlyOperations() override;
    void displayAccountInfo() const override;
    
    // Getter for FileManager
    double getMinimumBalance() const;
};

#endif