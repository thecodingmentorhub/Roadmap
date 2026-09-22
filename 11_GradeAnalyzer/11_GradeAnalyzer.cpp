#include <iomanip>
#include <iostream>
#include <string>

// Function declarations
int readValidMark(int markNumber);

double calculateAverage(const int marks[], int subjectCount);

int findHighestMark(const int marks[], int subjectCount);

int findLowestMark(const int marks[], int subjectCount);

std::string getResult(
    const int marks[],
    int subjectCount,
    double average);

char getGrade(
    const int marks[],
    int subjectCount,
    double average);

void displayResult(
    double average,
    int highest,
    int lowest,
    const std::string& result,
    char grade);


int main()
{
    const int subjectCount{ 5 };

    int marks[subjectCount]{};

    std::cout << "GRADE ANALYZER\n";
    std::cout << "--------------------------------\n";

    // Step 1: Read and validate marks
    for (int index{}; index < subjectCount; index++)
    {
        marks[index] = readValidMark(index + 1);
    }

    // Display entered marks
    std::cout << "\nMARKS ENTERED\n";
    std::cout << "--------------------------------\n";

    for (int index{}; index < subjectCount; index++)
    {
        std::cout << "Subject " << index + 1
            << ": " << marks[index]
            << '\n';
    }

    // Step 2: Calculate average
    double average{
        calculateAverage(marks, subjectCount)
    };

    // Step 3: Find highest mark
    int highest{
        findHighestMark(marks, subjectCount)
    };

    // Step 4: Find lowest mark
    int lowest{
        findLowestMark(marks, subjectCount)
    };

    // Step 5: Determine Pass / Fail
    std::string result{
        getResult(marks, subjectCount, average)
    };

    // Step 6: Determine Grade
    char grade{
        getGrade(marks, subjectCount, average)
    };

    // Step 7: Display final result
    displayResult(
        average,
        highest,
        lowest,
        result,
        grade);

    return 0;
}


// Read and validate one subject mark
int readValidMark(int markNumber)
{
    int mark{};

    while (true)
    {
        std::cout << "Enter mark for Subject "
            << markNumber
            << " (0-100): ";

        std::cin >> mark;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');

            std::cout << "Invalid input. "
                << "Please enter a number.\n";

            continue;
        }

        if (mark < 0 || mark > 100)
        {
            std::cout << "Invalid mark. "
                << "Enter a value between 0 and 100.\n";

            continue;
        }

        return mark;
    }
}


// Calculate average of all subjects
double calculateAverage(
    const int marks[],
    int subjectCount)
{
    int total{};

    for (int index{}; index < subjectCount; index++)
    {
        total += marks[index];
    }

    return static_cast<double>(total) / subjectCount;
}


// Find highest mark
int findHighestMark(
    const int marks[],
    int subjectCount)
{
    int highest{ marks[0] };

    for (int index{ 1 }; index < subjectCount; index++)
    {
        if (marks[index] > highest)
        {
            highest = marks[index];
        }
    }

    return highest;
}


// Find lowest mark
int findLowestMark(
    const int marks[],
    int subjectCount)
{
    int lowest{ marks[0] };

    for (int index{ 1 }; index < subjectCount; index++)
    {
        if (marks[index] < lowest)
        {
            lowest = marks[index];
        }
    }

    return lowest;
}


// Determine Pass / Fail
//
// Rule:
// If ANY subject is below 35 -> Fail
// Otherwise, if average is 35 or above -> Pass
std::string getResult(
    const int marks[],
    int subjectCount,
    double average)
{
    for (int index{}; index < subjectCount; index++)
    {
        if (marks[index] < 35)
        {
            return "Fail";
        }
    }

    if (average >= 35.0)
    {
        return "Pass";
    }

    return "Fail";
}


// Determine Grade
//
// If ANY subject is below 35 -> F
//
// Otherwise:
// 90 - 100 -> A
// 80 - 89  -> B
// 70 - 79  -> C
// 60 - 69  -> D
// Below 60 -> F
char getGrade(
    const int marks[],
    int subjectCount,
    double average)
{
    // Check individual subject pass condition
    for (int index{}; index < subjectCount; index++)
    {
        if (marks[index] < 35)
        {
            return 'F';
        }
    }

    if (average >= 90.0)
    {
        return 'A';
    }

    if (average >= 80.0)
    {
        return 'B';
    }

    if (average >= 70.0)
    {
        return 'C';
    }

    if (average >= 60.0)
    {
        return 'D';
    }

    return 'F';
}


// Display final student result
void displayResult(
    double average,
    int highest,
    int lowest,
    const std::string& result,
    char grade)
{
    std::cout << "\nGRADE ANALYSIS\n";
    std::cout << "--------------------------------\n";

    std::cout << std::fixed
        << std::setprecision(2);

    std::cout << "Average Mark : "
        << average << '\n';

    std::cout << "Highest Mark : "
        << highest << '\n';

    std::cout << "Lowest Mark  : "
        << lowest << '\n';

    std::cout << "Result       : "
        << result << '\n';

    std::cout << "Grade        : "
        << grade << '\n';
}