#include <iostream>
#include <string>

// --------------------------------------------------
// Base Class: Employee
// --------------------------------------------------
class Employee
{
private:
    std::string name;
    int id;

public:
    Employee(const std::string& employeeName, int employeeId)
        : name(employeeName), id(employeeId)
    {
    }

    virtual ~Employee() = default;

    const std::string& getName() const
    {
        return name;
    }

    int getId() const
    {
        return id;
    }

    virtual void displayRole() const
    {
        std::cout << "Role: Employee\n";
    }
};


// --------------------------------------------------
// Derived Class: Developer
// --------------------------------------------------
class Developer : public Employee
{
private:
    std::string programmingLanguage;

public:
    Developer(
        const std::string& employeeName,
        int employeeId,
        const std::string& language)
        : Employee(employeeName, employeeId),
        programmingLanguage(language)
    {
    }

    void displayRole() const override
    {
        std::cout << "Role: Developer\n";
        std::cout << "Programming Language: "
            << programmingLanguage << '\n';
    }

    const std::string& getProgrammingLanguage() const
    {
        return programmingLanguage;
    }
};


// --------------------------------------------------
// Derived Class: Manager
// --------------------------------------------------
class Manager : public Employee
{
private:
    int teamSize;

public:
    Manager(
        const std::string& employeeName,
        int employeeId,
        int numberOfTeamMembers)
        : Employee(employeeName, employeeId),
        teamSize(numberOfTeamMembers)
    {
    }

    void displayRole() const override
    {
        std::cout << "Role: Manager\n";
        std::cout << "Team Size: " << teamSize << '\n';
    }

    int getTeamSize() const
    {
        return teamSize;
    }
};


// --------------------------------------------------
// Function accepting the base-class reference
// --------------------------------------------------
void printEmployeeDetails(const Employee& employee)
{
    std::cout << "Employee Name: "
        << employee.getName() << '\n';

    std::cout << "Employee ID: "
        << employee.getId() << '\n';

    employee.displayRole();

    std::cout << "-----------------------------\n";
}


// --------------------------------------------------
// Main
// --------------------------------------------------
int main()
{
    Developer developer{
        "Sravani",
        101,
        "C++"
    };

    Manager manager{
        "Ravi",
        102,
        5
    };

    std::cout << "EMPLOYEE DETAILS\n";
    std::cout << "=============================\n\n";

    // Developer is-a Employee
    printEmployeeDetails(developer);

    // Manager is-a Employee
    printEmployeeDetails(manager);

    return 0;
}