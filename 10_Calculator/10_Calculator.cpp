#include <iostream>
#include <limits>
#include <string>

// Function declarations
double add(double firstNumber, double secondNumber);
double subtract(double firstNumber, double secondNumber);
double multiply(double firstNumber, double secondNumber);
double divide(double firstNumber, double secondNumber);

// Validation function declarations
bool isValidOperator(char operation);
bool readNumber(const std::string& message, double& number);


// --------------------------------------------------
// Main
// --------------------------------------------------
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
        // Read first number
        if (!readNumber("Enter first number: ", firstNumber))
        {
            std::cout << "Error: Invalid number entered.\n";
            continue;
        }

        // Read operator
        std::cout << "Enter operator (+, -, *, /): ";
        std::cin >> operation;

        // Validate operator
        if (!isValidOperator(operation))
        {
            std::cout << "Error: Invalid operator. "
                << "Please use +, -, * or /.\n";

            // Clear remaining input
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        // Read second number
        if (!readNumber("Enter second number: ", secondNumber))
        {
            std::cout << "Error: Invalid number entered.\n";
            continue;
        }

        // Handle division by zero
        if (operation == '/' && secondNumber == 0)
        {
            std::cout << "Error: Cannot divide by zero.\n";
        }
        else
        {
            double result{};

            switch (operation)
            {
            case '+':
                result = add(firstNumber, secondNumber);
                break;

            case '-':
                result = subtract(firstNumber, secondNumber);
                break;

            case '*':
                result = multiply(firstNumber, secondNumber);
                break;

            case '/':
                result = divide(firstNumber, secondNumber);
                break;
            }

            std::cout << "Result: " << result << '\n';
        }

        std::cout << "\nDo you want to continue? (y/n): ";
        std::cin >> continueChoice;

        // Handle invalid continuation input
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');

            continueChoice = 'n';
        }
    }

    std::cout << "\nCalculator closed.\n";

    return 0;
}


// --------------------------------------------------
// Addition
// --------------------------------------------------
double add(double firstNumber, double secondNumber)
{
    return firstNumber + secondNumber;
}


// --------------------------------------------------
// Subtraction
// --------------------------------------------------
double subtract(double firstNumber, double secondNumber)
{
    return firstNumber - secondNumber;
}


// --------------------------------------------------
// Multiplication
// --------------------------------------------------
double multiply(double firstNumber, double secondNumber)
{
    return firstNumber * secondNumber;
}


// --------------------------------------------------
// Division
// --------------------------------------------------
double divide(double firstNumber, double secondNumber)
{
    return firstNumber / secondNumber;
}


// --------------------------------------------------
// Validate operator
// --------------------------------------------------
bool isValidOperator(char operation)
{
    return operation == '+' ||
        operation == '-' ||
        operation == '*' ||
        operation == '/';
}


// --------------------------------------------------
// Read and validate number
// --------------------------------------------------
bool readNumber(const std::string& message, double& number)
{
    std::cout << message;
    std::cin >> number;

    if (std::cin.fail())
    {
        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }

    return true;
}