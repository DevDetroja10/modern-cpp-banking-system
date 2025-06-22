#ifndef BUSINESSACCOUNT_H
#define BUSINESSACCOUNT_H
#include "Account.h"
using namespace std;

class BusinessAccount : public Account {
private:
    double transactionFee;
    int freeTransactionLimit;
    int transactionCount;

public:
    BusinessAccount(int id, string name, double balance, 
                    double transactionFee = 2.0, int freeTransactionLimit = 50);
    
    string getAccountType() const override;
    bool withdraw(double amount) override;
    void deposit(double amount) override;
    void applyMonthlyOperations() override;
    void displayAccountInfo() const override;
    
    // Additional getters and setters for FileManager
    double getTransactionFee() const;
    int getFreeTransactionLimit() const;
    int getTransactionCount() const;
    void setTransactionCount(int count);
};

#endif