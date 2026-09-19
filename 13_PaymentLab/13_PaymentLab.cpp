// 13_PaymentLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Base class
class Payment
{
public:
    // Virtual function
    virtual void pay(double amount) = 0;

    // Virtual destructor
    virtual ~Payment() = default;
};

// Derived class: CardPayment
class CardPayment : public Payment
{
public:
    void pay(double amount) override
    {
        cout << "Card: Processing " << amount << endl;
    }
};

// Derived class: UPIPayment
class UPIPayment : public Payment
{
public:
    void pay(double amount) override
    {
        cout << "UPI : Processing " << amount << endl;
    }
};

// Derived class: CashPayment
class CashPayment : public Payment
{
public:
    void pay(double amount) override
    {
        cout << "Cash: Processing " << amount << endl;
    }
};

int main()
{
    CardPayment card;
    UPIPayment upi;
    CashPayment cash;

    // Common Payment interface
    Payment* payments[] = { &card, &upi, &cash };

    payments[0]->pay(1500);
    payments[1]->pay(750);
    payments[2]->pay(300);

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
