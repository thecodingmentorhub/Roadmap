#include <iostream>

double calculate(double firstNumber, char operation, double secondNumber);

int main()
{
    double firstNumber{};
    double secondNumber{};
    char operation{};
    char continueChoice{ 'y' };

    std::cout << "CALCULATOR\n";
    std::cout << "--------------------------------\n";

    while (continueChoice == 'y' || continueChoice == 'Y')
    {
        std::cout << "\nEnter first number: ";
        std::cin >> firstNumber;

        std::cout << "Enter operator (+, -, *, /): ";
        std::cin >> operation;

        std::cout << "Enter second number: ";
        std::cin >> secondNumber;

        if (operation == '/' && secondNumber == 0)
        {
            std::cout << "Error: Cannot divide by zero.\n";
        }
        else
        {
            double result{
                calculate(firstNumber, operation, secondNumber)
            };

            std::cout << "Result: " << result << '\n';
        }

        std::cout << "\nDo you want to continue? (y/n): ";
        std::cin >> continueChoice;
    }

    std::cout << "\nCalculator closed.\n";

    return 0;
}


double calculate(double firstNumber, char operation, double secondNumber)
{
    switch (operation)
    {
    case '+':
        return firstNumber + secondNumber;

    case '-':
        return firstNumber - secondNumber;

    case '*':
        return firstNumber * secondNumber;

    case '/':
        return firstNumber / secondNumber;

    default:
        std::cout << "Invalid operator.\n";
        return 0.0;
    }
}