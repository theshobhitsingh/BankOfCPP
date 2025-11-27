# <image href = "https://github.com/theshobhitsingh/BankOfCPP/blob/main/C++%20Bank%20Project.png?raw=true">
# 🏦 Bank of C++ - Console Banking System

## 🚀 Overview
A fully functional console-based banking application built in C++ featuring core banking operations with modern emoji-enhanced UI, PIN security, and efficient data management using `std::map`. Users can create accounts, perform transactions, and manage profiles securely.

## ✨ Features
- Account creation with auto-generated numbers (starting 1001) and timestamps
- PIN verification for sensitive operations (withdraw, transfer, edit, close)
- Deposits, withdrawals (insufficient funds protection), and account-to-account transfers
- Balance checks, profile editing, and full account listing
- Smart UX: Remembers last account; colored ANSI styling with dividers
- In-memory persistence with O(log n) lookups via `std::map<int, Account>`

## 🏗️ Architecture

### Core Components
| Component | Purpose | Key Data/Methods |
|-----------|---------|------------------|
| `Account` | Data holder | `accountNumber`, `balance`, `pin`, `creationDate` |
| `Bank` | Main logic | Private `map`, `verifyPIN()`, `promptAccountNumber()` |
| Helpers | UI/utils | `styledTitle()`, `displayTime()` with `put_time()` |

Follows OOP encapsulation with private data access via public methods.

## 📋 Quick Start
// Compile with: g++ -std=c++11 bank.cpp -o bank
// Run: ./bank

1. Enter name to start
2. Choose option 1 to create account (sets PIN, initial deposit)
3. Use account number + PIN for operations
4. Exit with option 9

## 🎨 UI Demo
🧭 🏦 Main Menu 🧭 <br>
1️⃣ Open New Account <br>
2️⃣ Check Balance <br>
3️⃣ Deposit Money <br>
4️⃣ Withdraw Money <br>
5️⃣ Transfer Money <br>
6️⃣ List All Accounts <br>
7️⃣ Close Account <br>
8️⃣ Edit Profile <br>
9️⃣ Exit <br>

🔍 Choose an option (1-9):

## 🔧 Key Implementation Highlights

### PIN Security Pattern


### Smart Account Prompt
- Offers last created account for convenience <br>
- Falls back to manual entry if declined <br>

### Time Formatting

## 📊 Error Handling
- Invalid inputs (negative amounts, wrong PINs) <br>
- Account existence checks before operations <br>
- Insufficient funds prevention <br>
- Graceful fallbacks in menu loops <br>

## ⚙️ Technical Specs
- **C++ Standard**: C++11+ (`put_time`, `numeric_limits`)
- **Dependencies**: STL only (`map`, `string`, `ctime`, `iomanip`)
- **Storage**: In-memory (restart clears data)
- **Terminal**: ANSI colors (Linux/Mac; Windows may need config)

## 🚀 Future Enhancements
- File persistence (JSON/CSV) <br>
- Transaction history logging <br>
- Multi-user sessions <br>
- Interest calculation <br>
- Database integration <br>

## Author
Shobhit Singh
