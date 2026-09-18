// 12_BankingLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// TransactionLimit controls the maximum amount
// that can be withdrawn in a single transaction.
class TransactionLimit
{
private:
    double maxWithdrawal;

public:
    TransactionLimit(double limit)
        : maxWithdrawal(limit)
    {
    }

    bool canWithdraw(double amount) const
    {
        return amount <= maxWithdrawal;
    }
};

// BankAccount manages the account balance.
class BankAccount
{
private:
    double balance;
    TransactionLimit limit;

public:
    BankAccount(double initialBalance, double withdrawalLimit)
        : balance(initialBalance),
        limit(withdrawalLimit)
    {
        if (initialBalance < 0)
        {
            balance = 0;
        }
    }

    // Deposit money into the account
    bool deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Deposit rejected: amount must be positive." << endl;
            return false;
        }

        balance += amount;
        cout << "Deposit successful: " << amount << endl;
        return true;
    }

    // Withdraw money from the account
    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Withdrawal rejected: amount must be positive." << endl;
            return false;
        }

        if (amount > balance)
        {
            cout << "Withdrawal rejected: insufficient balance." << endl;
            return false;
        }

        if (!limit.canWithdraw(amount))
        {
            cout << "Withdrawal rejected: transaction limit exceeded." << endl;
            return false;
        }

        balance -= amount;
        cout << "Withdrawal successful: " << amount << endl;
        return true;
    }

    // Read-only operation to check balance
    double getBalance() const
    {
        return balance;
    }
};

int main()
{
    BankAccount account(5000.0, 2000.0);

    cout << "Initial Balance: "
        << account.getBalance() << endl;

    account.deposit(1000);

    account.withdraw(1500);

    // Negative deposit
    account.deposit(-500);

    // Exceeds available balance
    account.withdraw(6000);

    // Exceeds transaction limit
    account.withdraw(3000);

    cout << "Final Balance: "
        << account.getBalance() << endl;

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
