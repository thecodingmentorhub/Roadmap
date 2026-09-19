
#include <iostream>
#include <iomanip>

// Function declarations
int readValidMark(int markNumber);

double calculateAverage(const int marks[], int size);
int findHighest(const int marks[], int size);
int findLowest(const int marks[], int size);

#include <iostream>

int readValidMark(int markNumber);

int main()
{
    std::cout << "GRADE ANALYZER\n";
    std::cout << "--------------------------------\n";

    int marks[5]{};

    // -----------------------------------------
    // Read five valid marks
    // -----------------------------------------
    for (int index{}; index < 5; index++)
    {
        marks[index] = readValidMark(index + 1);
    }

    // -----------------------------------------
    // Display marks entered
    // -----------------------------------------
    std::cout << "\nMARKS ENTERED\n";
    std::cout << "--------------------------------\n";

    for (int index{}; index < 5; index++)
    {
        std::cout << "Mark " << index + 1
            << ": " << marks[index]
            << '\n';
    }

    // -----------------------------------------
    // Calculate results
    // -----------------------------------------
    double average = calculateAverage(marks, 5);
    int highest = findHighest(marks, 5);
    int lowest = findLowest(marks, 5);

    // -----------------------------------------
    // Display results
    // -----------------------------------------
    std::cout << "\nGRADE ANALYSIS\n";
    std::cout << "--------------------------------\n";

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Average Mark : " << average << '\n';
    std::cout << "Highest Mark : " << highest << '\n';
    std::cout << "Lowest Mark  : " << lowest << '\n';

    return 0;
}


// --------------------------------------------------
// Read and validate a mark
// --------------------------------------------------
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


// --------------------------------------------------
// Calculate average of five marks
// --------------------------------------------------
double calculateAverage(const int marks[], int size)
{
    int total{};

    for (int index{}; index < size; index++)
    {
        total += marks[index];
    }

    return static_cast<double>(total) / size;
}


// --------------------------------------------------
// Find the highest mark
// --------------------------------------------------
int findHighest(const int marks[], int size)
{
    int highest = marks[0];

    for (int index{ 1 }; index < size; index++)
    {
        if (marks[index] > highest)
        {
            highest = marks[index];
        }
    }

    return highest;
}


// --------------------------------------------------
// Find the lowest mark
// --------------------------------------------------
int findLowest(const int marks[], int size)
{
    int lowest = marks[0];

    for (int index{ 1 }; index < size; index++)
    {
        if (marks[index] < lowest)
        {
            lowest = marks[index];
        }
    }

    return lowest;
}
}
