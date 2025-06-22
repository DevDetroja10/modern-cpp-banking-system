#include <iostream>
#include "Bank.h"
#include "FileManager.h"
using namespace std;

void printMenu() {
    cout << "\n=== Banking System ===" << endl;
    cout << "1. Add Savings Account" << endl;
    cout << "2. Add Checking Account" << endl;
    cout << "3. Add Business Account" << endl;
    cout << "4. Deposit" << endl;
    cout << "5. Withdraw" << endl;
    cout << "6. Show All Accounts" << endl;
    cout << "7. Apply Monthly Operations" << endl;
    cout << "8. Save All Accounts" << endl;
    cout << "9. Load All Accounts" << endl;
    cout << "10. Find Account by ID" << endl;
    cout << "11. Find Account by Name" << endl;
    cout << "12. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    Bank bank;
    
    // Add some sample accounts to demonstrate
    bank.addSavingsAccount(1001, "Alice", 1000.0, 0.03, 50.0);
    bank.addCheckingAccount(2001, "Bob", 500.0, 300.0, 12.0);
    bank.addBusinessAccount(3001, "CompanyXYZ", 5000.0, 1.5, 100);
    
    cout << "Welcome to the Enhanced Banking System!" << endl;
    cout << "Sample accounts have been created for demonstration." << endl;
    cout << "Function Overloading Demo: findAccount() works with both ID and Name!" << endl;
    
    bool running = true;
    while (running) {
        printMenu();
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int id;
                string name;
                double balance, interestRate, minBalance;
                cout << "Enter ID, Name, Initial Balance, Interest Rate (0.02 for 2%), Min Balance: ";
                cin >> id >> name >> balance >> interestRate >> minBalance;
                bank.addSavingsAccount(id, name, balance, interestRate, minBalance);
                cout << "Savings account added successfully!" << endl;
                break;
            }
            case 2: {
                int id;
                string name;
                double balance, overdraftLimit, monthlyFee;
                cout << "Enter ID, Name, Initial Balance, Overdraft Limit, Monthly Fee: ";
                cin >> id >> name >> balance >> overdraftLimit >> monthlyFee;
                bank.addCheckingAccount(id, name, balance, overdraftLimit, monthlyFee);
                cout << "Checking account added successfully!" << endl;
                break;
            }
            case 3: {
                int id;
                string name;
                double balance, transactionFee;
                int freeTransactionLimit;
                cout << "Enter ID, Name, Initial Balance, Transaction Fee, Free Transaction Limit: ";
                cin >> id >> name >> balance >> transactionFee >> freeTransactionLimit;
                bank.addBusinessAccount(id, name, balance, transactionFee, freeTransactionLimit);
                cout << "Business account added successfully!" << endl;
                break;
            }
            case 4: {
                int id;
                double amount;
                cout << "Enter ID and amount to deposit: ";
                cin >> id >> amount;
                if (bank.deposit(id, amount)) {
                    cout << "Deposit successful!" << endl;
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 5: {
                int id;
                double amount;
                cout << "Enter ID and amount to withdraw: ";
                cin >> id >> amount;
                if (bank.withdraw(id, amount)) {
                    cout << "Withdrawal successful!" << endl;
                } else {
                    cout << "Account not found, insufficient funds, or withdrawal violates account rules." << endl;
                }
                break;
            }
            case 6: {
                bank.displayAllAccounts();
                break;
            }
            case 7: {
                bank.applyMonthlyOperationsToAll();
                break;
            }
            case 8: {
                FileManager::saveAllAccounts(bank);
                break;
            }
            case 9: {
                FileManager::loadAllAccounts(bank);
                break;
            }
            case 10: {
                int id;
                cout << "Enter Account ID to search: ";
                cin >> id;
                bank.findAccount(id);  // Function overloading - calls findAccount(int)
                break;
            }
            case 11: {
                string name;
                cout << "Enter Account Name to search: ";
                cin >> name;
                bank.findAccount(name);  // Function overloading - calls findAccount(string)
                break;
            }
            case 12: {
                cout << "Thank you for using our banking system!" << endl;
                running = false;
                break;
            }
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    
    return 0;
}