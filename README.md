# 🏦 Bank Management System - OOP Implementation

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)

**Complete demonstration of Object-Oriented Programming principles in C++**

</div>

---

## 🎯 Project Overview

A comprehensive Bank Management System showcasing **all four OOP principles** with multiple account types, file persistence, and interactive functionality. Perfect demonstration of real-world C++ application development.

---

## 🧬 OOP Concepts Implemented

### **1. Inheritance** 🧬
- **Abstract Base Class**: `Account` with pure virtual functions
- **Derived Classes**: `SavingsAccount`, `CheckingAccount`, `BusinessAccount`
- **Code Reusability**: Common functionality in base, specialized behavior in derived classes

### **2. Polymorphism** 🔄
- **Compile-time Polymorphism**: Function overloading with `findAccount(int id)` vs `findAccount(string name)`
- **Runtime Polymorphism (Future-ready)**: Virtual functions enable polymorphic behavior through base class pointers
- **Pure Virtual Functions**: `getAccountType()` enforces implementation in all derived classes

### **3. Encapsulation** 🔒
- **Private Members**: Account-specific attributes hidden from external access
- **Protected Members**: Base class data accessible to derived classes only
- **Public Interface**: Controlled access through getter/setter methods

### **4. Abstraction** 🎭
- **Abstract Base Class**: `Account` cannot be instantiated directly

---

## 🏗️ System Architecture

```
Account (Abstract Base)
├── SavingsAccount (Interest Rate + Minimum Balance)
├── CheckingAccount (Overdraft + Monthly Fees)
└── BusinessAccount (Transaction Fees + Free Limits)

Bank (Management Layer)
├── Account Operations (Deposit/Withdraw/Display)
├── Function Overloading (Search by ID/Name)
└── Monthly Operations (Interest/Fees)

FileManager (Persistence Layer)
├── Save All Accounts to File
└── Load All Accounts from File
```

---

## 🚀 Key Features

### **Core Banking Operations**
- ✅ **Multiple Account Types**: Savings, Checking, Business with unique behaviors
- ✅ **Transaction Management**: Deposits, withdrawals with business rule validation
- ✅ **Account Search**: Find by ID or Name (demonstrates function overloading)
- ✅ **Monthly Operations**: Interest calculation, fee application, transaction resets

### **OOP Demonstrations**
- ✅ **Complete Inheritance Hierarchy**: Base → Derived with proper method overriding
- ✅ **Polymorphism**: Both compile-time (overloading) and runtime (virtual functions) - Future ready
- ✅ **Data Encapsulation**: Private/protected access with controlled interfaces
- ✅ **Pure Abstraction**: Abstract base class forcing implementation contracts

### **Advanced Features**
- ✅ **File Persistence**: Save/load complete bank state
- ✅ **Interactive Console**: 12-option menu system
- ✅ **Error Handling**: Validation and graceful error management
- ✅ **Sample Data**: Pre-loaded accounts for immediate testing

---

## 🔧 Account Types & Specializations

| Account Type | Key Features | Special Behavior |
|--------------|--------------|------------------|
| **Savings** | Interest Rate, Minimum Balance | Monthly interest calculation, balance enforcement |
| **Checking** | Overdraft Limit, Monthly Fee | Overdraft protection, fee deduction, transaction tracking |
| **Business** | Transaction Fee, Free Limits | Per-transaction fees after free limit, monthly resets |

---

## 💻 Quick Start

```bash
# Compile
g++ -std=c++20 *.cpp -o bank_system

# Run
./bank_system
```

**Sample Operations:**
- Create accounts of different types
- Perform deposits/withdrawals with type-specific rules
- Search accounts by ID or name (function overloading demo)
- Apply monthly operations (interest, fees, resets)
- Save/load complete bank state to/from file

---

<div align="center">

*✨ Perfect demonstration of C++ Object-Oriented Programming mastery*

</div>
