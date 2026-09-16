#include <iostream>
#include <iomanip>
#include <string>

// --------------------------------------------------
// Calculate parking fee based on hours
// --------------------------------------------------
double calculateFee(int hours)
{
    if (hours <= 0)
    {
        return -1.0;   // Invalid input
    }

    double ratePerHour{};

    if (hours <= 2)
    {
        // Short stay
        ratePerHour = 20.0;
    }
    else if (hours <= 5)
    {
        // Medium stay
        ratePerHour = 30.0;
    }
    else
    {
        // Long stay
        ratePerHour = 40.0;
    }

    return hours * ratePerHour;
}

// --------------------------------------------------
// Overloaded function - calculate fee with discount
// --------------------------------------------------
double calculateFee(int hours, double discountPercentage)
{
    if (hours <= 0 || discountPercentage < 0 || discountPercentage > 100)
    {
        return -1.0;   // Invalid input
    }

    double originalFee = calculateFee(hours);

    double discountAmount =
        originalFee * discountPercentage / 100.0;

    return originalFee - discountAmount;
}

// --------------------------------------------------
// Print parking receipt
// --------------------------------------------------
void printReceipt(int hours, double fee)
{
    std::cout << "\n";
    std::cout << "====================================\n";
    std::cout << "          PARKING RECEIPT            \n";
    std::cout << "====================================\n";

    std::cout << "Hours Parked : " << hours << "\n";

    if (hours <= 2)
    {
        std::cout << "Stay Type    : Short Stay\n";
        std::cout << "Rate         : Rs.20/hour\n";
    }
    else if (hours <= 5)
    {
        std::cout << "Stay Type    : Medium Stay\n";
        std::cout << "Rate         : Rs.30/hour\n";
    }
    else
    {
        std::cout << "Stay Type    : Long Stay\n";
        std::cout << "Rate         : Rs.40/hour\n";
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total Fee    : Rs." << fee << "\n";

    std::cout << "====================================\n";
}

// --------------------------------------------------
// Test boundary values
// --------------------------------------------------
void testBoundaryValues()
{
    std::cout << "\n";
    std::cout << "========== BOUNDARY VALUE TESTS ==========\n";

    int testHours[] = { 1, 2, 3, 5, 6 };

    for (int hours : testHours)
    {
        double fee = calculateFee(hours);

        std::cout << "Hours: " << hours
            << " -> Fee: Rs."
            << std::fixed << std::setprecision(2)
            << fee << "\n";
    }
}

// --------------------------------------------------
// Main function
// --------------------------------------------------
int main()
{
    int hours{};
    double discount{};

    std::cout << "====================================\n";
    std::cout << "       PARKING FEE APPLICATION       \n";
    std::cout << "====================================\n";

    // Input hours
    std::cout << "Enter hours parked: ";
    std::cin >> hours;

    // Validate hours
    if (std::cin.fail() || hours <= 0)
    {
        std::cout << "Error: Invalid number of hours.\n";
        return 1;
    }

    // Calculate normal fee
    double fee = calculateFee(hours);

    // Display normal receipt
    printReceipt(hours, fee);

    // Ask for discount
    std::cout << "\nEnter discount percentage (0-100): ";
    std::cin >> discount;

    if (std::cin.fail() || discount < 0 || discount > 100)
    {
        std::cout << "Error: Invalid discount percentage.\n";
        return 1;
    }

    // Use overloaded function
    double discountedFee = calculateFee(hours, discount);

    std::cout << "\n========== DISCOUNTED RECEIPT ==========\n";
    std::cout << "Hours Parked : " << hours << "\n";
    std::cout << "Discount     : " << discount << "%\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Final Fee    : Rs." << discountedFee << "\n";

    // Test boundary values
    testBoundaryValues();

    return 0;
}