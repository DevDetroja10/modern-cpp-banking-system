#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

const string FileManager::DATA_FILE = "bank_data.txt";

void FileManager::saveAllAccounts(const Bank& bank) {
    try {
        ofstream file(DATA_FILE);
        if (!file.is_open()) {
            throw runtime_error("Cannot open file for writing: " + DATA_FILE);
        }
        
        // Save Savings Accounts
        for (const auto& acc : bank.getSavingsAccounts()) {
            file << "SAVINGS " << acc.getId() << " " << acc.getName() << " " 
                 << acc.getBalance() << " " << acc.getInterestRate() << " " 
                 << acc.getMinimumBalance() << endl;
        }
        
        // Save Checking Accounts  
        for (const auto& acc : bank.getCheckingAccounts()) {
            file << "CHECKING " << acc.getId() << " " << acc.getName() << " " 
                 << acc.getBalance() << " " << acc.getOverdraftLimit() << " " 
                 << acc.getMonthlyFee() << " " << acc.getTransactionCount() << endl;
        }
        
        // Save Business Accounts
        for (const auto& acc : bank.getBusinessAccounts()) {
            file << "BUSINESS " << acc.getId() << " " << acc.getName() << " " 
                 << acc.getBalance() << " " << acc.getTransactionFee() << " " 
                 << acc.getFreeTransactionLimit() << " " << acc.getTransactionCount() << endl;
        }
        
        file.close();
        cout << "All accounts saved to " << DATA_FILE << endl;
    }
    catch (const exception& e) {
        cout << "Error saving accounts: " << e.what() << endl;
    }
}

void FileManager::loadAllAccounts(Bank& bank) {
    try {
        ifstream file(DATA_FILE);
        if (!file.is_open()) {
            cout << "No saved data found. Starting fresh." << endl;
            return;
        }
        
        bank.clearAllAccounts();
        
        string type;
        while (file >> type) {
            if (type == "SAVINGS") {
                int id;
                string name;
                double balance, interestRate, minBalance;
                file >> id >> name >> balance >> interestRate >> minBalance;
                bank.addSavingsAccount(id, name, balance, interestRate, minBalance);
            }
            else if (type == "CHECKING") {
                int id, transactionCount;
                string name;
                double balance, overdraftLimit, monthlyFee;
                file >> id >> name >> balance >> overdraftLimit >> monthlyFee >> transactionCount;
                bank.addCheckingAccount(id, name, balance, overdraftLimit, monthlyFee);
                // Note: Transaction count will be reset to 0 (this is acceptable for simplicity)
            }
            else if (type == "BUSINESS") {
                int id, freeLimit, transactionCount;
                string name;
                double balance, transactionFee;
                file >> id >> name >> balance >> transactionFee >> freeLimit >> transactionCount;
                bank.addBusinessAccount(id, name, balance, transactionFee, freeLimit);
                // Note: Transaction count will be reset to 0 (this is acceptable for simplicity)
            }
        }
        
        file.close();
        cout << "All accounts loaded from " << DATA_FILE << endl;
    }
    catch (const exception& e) {
        cout << "Error loading accounts: " << e.what() << endl;
    }
}