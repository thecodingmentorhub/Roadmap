#include <iostream>

int readValidMark(int markNumber);

int main()
{
    std::cout << "GRADE ANALYZER\n";
    std::cout << "--------------------------------\n";

    int marks[5]{};

    for (int index{}; index < 5; index++)
    {
        marks[index] = readValidMark(index + 1);
    }

    std::cout << "\nMARKS ENTERED\n";
    std::cout << "--------------------------------\n";

    for (int index{}; index < 5; index++)
    {
        std::cout << "Mark " << index + 1
            << ": " << marks[index]
            << '\n';
    }

    return 0;
}


int readValidMark(int markNumber)
{
    int mark{};

    while (true)
    {
        std::cout << "Enter mark " << markNumber
            << " (0-100): ";

        std::cin >> mark;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');

            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (mark < 0 || mark > 100)
        {
            std::cout << "Invalid mark. Enter a value between 0 and 100.\n";
            continue;
        }

        return mark;
    }
}