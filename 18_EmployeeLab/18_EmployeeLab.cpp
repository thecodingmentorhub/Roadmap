#include <iostream>
#include <string>
#include <iomanip>

// Base class
class Employee
{
private:
    std::string name;
    double baseSalary;

public:
    // Constructor
    Employee(const std::string& empName, double salary)
        : name(empName), baseSalary(salary)
    {
        if (baseSalary < 0)
        {
            baseSalary = 0;
        }
    }

    // Virtual destructor
    virtual ~Employee() = default;

    // Virtual function for runtime polymorphism
    virtual double calculateBonus() const = 0;

    // Getters
    const std::string& getName() const
    {
        return name;
    }

    double getBaseSalary() const
    {
        return baseSalary;
    }
};

// Derived class: Developer
class Developer : public Employee
{
public:
    Developer(const std::string& name, double salary)
        : Employee(name, salary)
    {
    }

    // Developer gets 10% bonus
    double calculateBonus() const override
    {
        return getBaseSalary() * 0.10;
    }
};

// Derived class: Manager
class Manager : public Employee
{
public:
    Manager(const std::string& name, double salary)
        : Employee(name, salary)
    {
    }

    // Manager gets 20% bonus
    double calculateBonus() const override
    {
        return getBaseSalary() * 0.20;
    }
};

// Works with Employee and any derived class
void printPayDetails(const Employee& employee)
{
    double bonus = employee.calculateBonus();
    double totalPay = employee.getBaseSalary() + bonus;

    std::cout << "Employee Name : " << employee.getName() << '\n';
    std::cout << "Base Salary   : $" << std::fixed
        << std::setprecision(2) << employee.getBaseSalary() << '\n';
    std::cout << "Bonus         : $" << bonus << '\n';
    std::cout << "Total Pay     : $" << totalPay << '\n';
    std::cout << "-----------------------------\n";
}

int main()
{
    Developer developer("John", 60000);
    Manager manager("Sarah", 90000);

    printPayDetails(developer);
    printPayDetails(manager);

    return 0;
}