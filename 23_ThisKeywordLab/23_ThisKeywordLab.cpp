#include <iostream>
#include <iomanip>
#include <string>

class BankAccount
{
private:
    std::string owner;
    double balance;

public:

    // Constructor
    // Parameter names intentionally match member names.
    BankAccount(std::string owner, double balance)
    {
        this->owner = owner;
        this->balance = balance;
    }


    // Setter
    // Parameter name intentionally matches member name.
    void setOwner(std::string owner)
    {
        this->owner = owner;
    }


    // Deposit money and return the current object.
    // Returning *this allows method chaining.
    BankAccount& deposit(double amount)
    {
        if (amount > 0)
        {
            this->balance += amount;
        }
        else
        {
            std::cout << "Deposit amount must be greater than zero."
                << std::endl;
        }

        return *this;
    }


    // Display account information.
    void display() const
    {
        std::cout << "\n========== Bank Account =========="
            << std::endl;

        std::cout << "Owner   : " << this->owner << std::endl;

        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Balance : " << this->balance << std::endl;
    }
};


int main()
{
    // Constructor parameters have the same names
    // as the member variables.
    BankAccount account("Shaik Moinuddin", 1000.00);

    std::cout << "Initial Account Details:";
    account.display();


    // Demonstrating deposit()
    account.deposit(100);

    std::cout << "\nAfter depositing 100:";
    account.display();


    // Method chaining
    account.deposit(100).deposit(50);

    std::cout << "\nAfter chained deposits of 100 and 50:";
    account.display();


    // Demonstrating setter using this->
    account.setOwner("Moinuddin");

    std::cout << "\nAfter changing account owner:";
    account.display();


    return 0;
}