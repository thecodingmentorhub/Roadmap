// 12_BankingLabclass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string accountHolder;
    std::string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(const std::string& holder,
        const std::string& number,
        double initialBalance)
        : accountHolder(holder),
        accountNumber(number),
        balance(initialBalance)
    {
        // Prevent an invalid initial balance
        if (balance < 0)
        {
            balance = 0;
        }
    }

    // Deposit money into the account
    bool deposit(double amount)
    {
        if (amount <= 0)
        {
            std::cout << "Invalid deposit amount.\n";
            return false;
        }

        balance += amount;
        std::cout << "Deposit: " << amount << '\n';

        return true;
    }

    // Withdraw money from the account
    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            std::cout << "Invalid withdrawal amount.\n";
            return false;
        }

        if (amount > balance)
        {
            std::cout << "Withdrawal rejected: insufficient balance.\n";
            return false;
        }

        balance -= amount;
        std::cout << "Withdraw: " << amount << '\n';

        return true;
    }

    // Read-only access to the balance
    double getBalance() const
    {
        return balance;
    }

    // Display account details
    void displayAccount() const
    {
        std::cout << "Account: " << accountNumber << '\n';
        std::cout << "Owner  : " << accountHolder << '\n';
    }
};

int main()
{
    BankAccount account("Alex", "ACC-101", 1000.0);

    account.displayAccount();

    std::cout << '\n';

    account.deposit(500);
    account.withdraw(200);

    std::cout << '\n';
    std::cout << "Balance: " << account.getBalance() << '\n';

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
