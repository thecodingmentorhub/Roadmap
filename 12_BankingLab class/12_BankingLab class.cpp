// 12_BankingLab class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string holder, string number, double initialBalance)
        : accountHolder(holder),
        accountNumber(number),
        balance(initialBalance)
    {
    }

    // Deposit money
    void deposit(double amount)
    {
        if (amount < 0)
        {
            cout << "Error: Deposit amount cannot be negative." << endl;
            return;
        }

        balance += amount;
        cout << "Deposit: " << amount << endl;
    }

    // Withdraw money
    void withdraw(double amount)
    {
        if (amount < 0)
        {
            cout << "Error: Withdrawal amount cannot be negative." << endl;
            return;
        }

        if (amount > balance)
        {
            cout << "Error: Insufficient balance." << endl;
            return;
        }

        balance -= amount;
        cout << "Withdraw: " << amount << endl;
    }

    // Get current balance
    double getBalance() const
    {
        return balance;
    }

    // Display account details
    void display() const
    {
        cout << "Account: " << accountNumber << endl;
        cout << "Owner : " << accountHolder << endl;
        cout << endl;
    }
};

int main()
{
    BankAccount account("Alex", "ACC-101", 1000);

    account.display();

    account.deposit(500);
    account.withdraw(200);

    cout << endl;
    cout << "Balance: " << account.getBalance() << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
