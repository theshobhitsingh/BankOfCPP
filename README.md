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
🧭 🏦 Main Menu 🧭
1️⃣ Open New Account
2️⃣ Check Balance
3️⃣ Deposit Money
4️⃣ Withdraw Money
5️⃣ Transfer Money
6️⃣ List All Accounts
7️⃣ Close Account
8️⃣ Edit Profile
9️⃣ Exit

🔍 Choose an option (1-9):

## 🔧 Key Implementation Highlights

### PIN Security Pattern


### Smart Account Prompt
- Offers last created account for convenience
- Falls back to manual entry if declined

### Time Formatting

## 📊 Error Handling
- Invalid inputs (negative amounts, wrong PINs)
- Account existence checks before operations
- Insufficient funds prevention
- Graceful fallbacks in menu loops

## ⚙️ Technical Specs
- **C++ Standard**: C++11+ (`put_time`, `numeric_limits`)
- **Dependencies**: STL only (`map`, `string`, `ctime`, `iomanip`)
- **Storage**: In-memory (restart clears data)
- **Terminal**: ANSI colors (Linux/Mac; Windows may need config)

## 🚀 Future Enhancements
- File persistence (JSON/CSV)
- Transaction history logging
- Multi-user sessions
- Interest calculation
- Database integration

## Author
Shobhit Singh
