#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;

struct Account
{
     int accountNumber;
     string name;
     double balance;
     time_t creationDate;
     string pin;
};

class Bank
{
private:
     map<int, Account> accounts;
     int nextAccountNumber = 1001;
     int currentAccountNumber = -1;

     void displayTime(time_t t)
     {
          tm *lt = localtime(&t);
          cout << put_time(lt, "%Y-%m-%d %H:%M:%S");
     }

     void printDivider()
     {
          cout << "\n\033[1;36m============================================\033[0m\n";
     }

     void styledTitle(const string &title)
     {
          printDivider();
          cout << "\033[1;33m\n🧭 " << title << " 🧭\033[0m\n";
          printDivider();
     }

     bool verifyPIN(const Account &acc)
     {
          string enteredPIN;
          cout << "🔐 Enter PIN: ";
          cin >> enteredPIN;
          return enteredPIN == acc.pin;
     }

public:
     void welcomeUser()
     {
          string userName;
          styledTitle("Welcome to the Bank of C++");
          cout << "👤 Enter your name: ";
          getline(cin, userName);
          cout << "\n🎉 Hello, " << userName << "Welcome to the \"Bank of C++\" \n";
          showMainMenu();
     }

     void showMainMenu()
     {
          while (true)
          {
               styledTitle("🏦 Main Menu");
               cout << "1️⃣  Open New Account\n";
               cout << "2️⃣  Check Balance\n";
               cout << "3️⃣  Deposit Money\n";
               cout << "4️⃣  Withdraw Money\n";
               cout << "5️⃣  Transfer Money\n";
               cout << "6️⃣  List All Accounts\n";
               cout << "7️⃣  Close Account\n";
               cout << "8️⃣  Edit Profile\n";
               cout << "9️⃣  Exit\n";
               cout << "\n🔍 Choose an option (1-9): ";

               int choice;
               cin >> choice;
               cin.ignore(numeric_limits<streamsize>::max(), '\n');

               switch (choice)
               {
               case 1:
                    openAccount();
                    break;
               case 2:
                    checkBalance();
                    break;
               case 3:
                    depositMoney();
                    break;
               case 4:
                    withdrawMoney();
                    break;
               case 5:
                    transferMoney();
                    break;
               case 6:
                    listAccounts();
                    break;
               case 7:
                    closeAccount();
                    break;
               case 8:
                    editProfile();
                    break;
               case 9:
                    styledTitle("👋 Thank You!");
                    cout << "🙏 Thank you for using the Bank of C++. Goodbye!\n";
                    return;
               default:
                    cout << "\n❌ Invalid option. Please try again.\n";
               }
          }
     }

     void openAccount()
     {
          styledTitle("📂 Open New Account");
          Account acc;
          acc.accountNumber = nextAccountNumber++;
          cout << "👤 Enter your Full name: ";
          getline(cin, acc.name);
          cout << "💵 Enter initial deposit amount: ";
          cin >> acc.balance;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "🔐 Set your 4-digit PIN: ";
          cin >> acc.pin;
          acc.creationDate = time(0);

          accounts[acc.accountNumber] = acc;
          currentAccountNumber = acc.accountNumber;

          cout << "\n✅ Account successfully created!\n";
          cout << "🔑 Account Number: " << acc.accountNumber << "\n";
          cout << "👤 Name: " << acc.name << "\n";
          cout << "💰 Balance: $" << fixed << setprecision(2) << acc.balance << "\n";
          cout << "📅 Created on: ";
          displayTime(acc.creationDate);
          cout << "\n\n📌 Please note your account number and PIN for future transactions.\n";
     }

     void checkBalance()
     {
          styledTitle("💳 Check Balance");
          int accNum = promptAccountNumber();
          if (accounts.find(accNum) != accounts.end())
          {
               if (verifyPIN(accounts[accNum]))
               {
                    cout << "👤 Account Holder: " << accounts[accNum].name << "\n";
                    cout << "💰 Balance: $" << fixed << setprecision(2) << accounts[accNum].balance << "\n";
               }
               else
               {
                    cout << "\n❌ Incorrect PIN.\n";
               }
          }
          else
          {
               cout << "\n❌ Account not found.\n";
          }
     }

     void depositMoney()
     {
          styledTitle("💸 Deposit Money");
          int accNum = promptAccountNumber();
          double amount;
          cout << "💵 Enter amount to deposit: ";
          cin >> amount;

          if (accounts.find(accNum) != accounts.end())
          {
               if (amount > 0)
               {
                    accounts[accNum].balance += amount;
                    cout << "\n✅ $" << fixed << setprecision(2) << amount << " deposited successfully.\n";
                    cout << "💰 New Balance: $" << accounts[accNum].balance << "\n";
               }
               else
               {
                    cout << "\n❌ Invalid deposit amount.\n";
               }
          }
          else
          {
               cout << "\n❌ Account not found.\n";
          }
     }

     void withdrawMoney()
     {
          styledTitle("🏧 Withdraw Money");
          int accNum = promptAccountNumber();
          double amount;
          cout << "💵 Enter amount to withdraw: ";
          cin >> amount;

          if (accounts.find(accNum) != accounts.end())
          {
               if (!verifyPIN(accounts[accNum]))
               {
                    cout << "\n❌ Incorrect PIN.\n";
                    return;
               }
               if (amount <= 0)
               {
                    cout << "\n❌ Invalid withdrawal amount.\n";
                    return;
               }
               if (accounts[accNum].balance >= amount)
               {
                    accounts[accNum].balance -= amount;
                    cout << "\n✅ $" << fixed << setprecision(2) << amount << " withdrawn successfully.\n";
                    cout << "💰 Remaining Balance: $" << accounts[accNum].balance << "\n";
               }
               else
               {
                    cout << "\n⚠️ Insufficient funds.\n";
               }
          }
          else
          {
               cout << "\n❌ Account not found.\n";
          }
     }

     void transferMoney()
     {
          styledTitle("🔄 Transfer Money");
          int fromAcc = promptAccountNumber();
          if (accounts.find(fromAcc) == accounts.end())
          {
               cout << "❌ Sender account not found.\n";
               return;
          }

          if (!verifyPIN(accounts[fromAcc]))
          {
               cout << "❌ Incorrect PIN.\n";
               return;
          }

          int toAcc;
          cout << "🔑 Enter destination account number: ";
          cin >> toAcc;

          if (accounts.find(toAcc) == accounts.end())
          {
               cout << "❌ Destination account not found.\n";
               return;
          }

          double amount;
          cout << "💸 Enter amount to transfer: ";
          cin >> amount;

          if (amount <= 0)
          {
               cout << "❌ Invalid amount.\n";
               return;
          }

          if (accounts[fromAcc].balance < amount)
          {
               cout << "⚠️ Insufficient balance.\n";
               return;
          }

          accounts[fromAcc].balance -= amount;
          accounts[toAcc].balance += amount;

          cout << "\n✅ $" << fixed << setprecision(2) << amount << " transferred from Account " << fromAcc << " to Account " << toAcc << ".\n";
     }

     void listAccounts()
     {
          styledTitle("📜 All Bank Accounts");
          if (accounts.empty())
          {
               cout << "🚫 No accounts found.\n";
          }
          else
          {
               for (const auto &pair : accounts)
               {
                    const Account &acc = pair.second;
                    cout << "\n🔑 Account Number: " << acc.accountNumber << "\n";
                    cout << "👤 Name: " << acc.name << "\n";
                    cout << "💰 Balance: $" << fixed << setprecision(2) << acc.balance << "\n";
                    cout << "📅 Created On: ";
                    displayTime(acc.creationDate);
                    cout << "\n";
               }
          }
     }

     void closeAccount()
     {
          styledTitle("❌ Close Account");
          int accNum = promptAccountNumber();
          if (accounts.find(accNum) != accounts.end())
          {
               if (verifyPIN(accounts[accNum]))
               {
                    accounts.erase(accNum);
                    cout << "\n✅ Account " << accNum << " has been successfully closed.\n";
                    if (currentAccountNumber == accNum)
                         currentAccountNumber = -1;
               }
               else
               {
                    cout << "\n❌ Incorrect PIN.\n";
               }
          }
          else
          {
               cout << "\n❌ Account not found.\n";
          }
     }

     void editProfile()
     {
          styledTitle("🛠️ Edit Profile");
          int accNum = promptAccountNumber();
          if (accounts.find(accNum) != accounts.end())
          {
               if (verifyPIN(accounts[accNum]))
               {
                    cout << "✏️ Enter new name: ";
                    cin.ignore();
                    getline(cin, accounts[accNum].name);
                    cout << "🔐 Enter new PIN: ";
                    cin >> accounts[accNum].pin;
                    cout << "\n✅ Profile updated successfully.\n";
               }
               else
               {
                    cout << "\n❌ Incorrect PIN.\n";
               }
          }
          else
          {
               cout << "\n❌ Account not found.\n";
          }
     }

     int promptAccountNumber()
     {
          int accNum;
          if (currentAccountNumber != -1)
          {
               cout << "\n🧾 Use your last created account (" << currentAccountNumber << ")? (y/n): ";
               char choice;
               cin >> choice;
               if (choice == 'y' || choice == 'Y')
               {
                    return currentAccountNumber;
               }
          }
          cout << "🔑 Enter account number: ";
          cin >> accNum;
          return accNum;
     }
};

int main()
{
     Bank bankApp;
     bankApp.welcomeUser();
     return 0;
}