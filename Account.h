#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account {
public:
    Account(int id, string name, double balance);
    virtual ~Account() = default;
    
    int getId() const;
    string getName() const;
    double getBalance() const;
    
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual string getAccountType() const = 0;  // Pure virtual
    virtual void displayAccountInfo() const;
    virtual double getInterestRate() const { return 0.0; }
    virtual void applyMonthlyOperations() {}  // For interest, fees, etc.

protected:
    int id;
    string name;
    double balance;
};

#endif