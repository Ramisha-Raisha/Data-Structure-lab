/*Create a structure named "BankAccount" with the following fields:
•	Account Number
•	Account Holder's Name
•	Account Balance
•	Write a C++ program that allows the user to:
1.	Create a new bank account.
2.	Deposit money into an account
3.	Withdraw money from an account.
4.	Display the account details.*/


#include <iostream>
#include <string>
using namespace std;

struct BankAccount {
    int accountNumber;
    string accountHolderName;
    double accountBalance;
};


BankAccount createAccount() {
    BankAccount account;
    cout << "Enter Account Number: ";
    cin >> account.accountNumber;
    cout << "Enter Account Holder's Name: ";
    cin.ignore();
    getline(cin, account.accountHolderName);
    cout << "Enter Initial Account Balance: ";
    cin >> account.accountBalance;
    return account;
}


void depositMoney(BankAccount &account, double amount) {
    if (amount > 0) {
        account.accountBalance += amount;
        cout << "Deposited tk" << amount << " into the account." << endl;
    } else {
        cout << "Invalid deposit amount. Please enter a positive amount." << endl;
    }
}


void withdrawMoney(BankAccount &account, double amount) {
    if (amount > 0 && amount <= account.accountBalance) {
        account.accountBalance -= amount;
        cout << "Withdrawn " << amount << " from the account." << endl;
    } else {
        cout << "Invalid withdrawal amount or insufficient balance." << endl;
    }
}


void displayAccountDetails(const BankAccount &account) {
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Account Holder's Name: " << account.accountHolderName << endl;
    cout << "Account Balance: " << account.accountBalance <<" tk"<< endl;
}

int main() {
    BankAccount account;


    account = createAccount();

    while (true) {
        cout << "Menu:"<<endl;
        cout << "1. Deposit Money"<<endl;
        cout << "2. Withdraw Money"<<endl;
        cout << "3. Display Account Details"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                depositMoney(account, amount);
                break;
            }
            case 2: {
                double amount;
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                withdrawMoney(account, amount);
                break;
            }
            case 3:
                displayAccountDetails(account);
                break;
            case 4:
                cout << " Exit"<<endl;
                return 0;

        }
    }

    return 0;
}
