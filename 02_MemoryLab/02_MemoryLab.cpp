#include <iostream>

// Function to update CPU usage
void updateUsage(double* usage)
{
    if (usage != nullptr)
    {
        *usage = 88.0;
    }
}

// StorageServer class
class StorageServer
{
private:
    double totalStorage;
    double usedStorage;

public:
    // Constructor
    StorageServer(double total, double used)
    {
        totalStorage = total;
        usedStorage = used;
    }

    // Display storage information
    void displayStorage()
    {
        std::cout << "\n--- Storage Server Information ---\n";
        std::cout << "Total Storage: " << totalStorage << " GB\n";
        std::cout << "Used Storage: " << usedStorage << " GB\n";
        std::cout << "Available Storage: "
            << totalStorage - usedStorage << " GB\n";
    }

    // Update used storage
    void updateUsedStorage(double newUsage)
    {
        if (newUsage >= 0 && newUsage <= totalStorage)
        {
            usedStorage = newUsage;
        }
        else
        {
            std::cout << "Invalid storage value!\n";
        }
    }
};

// Addition function
int doAdd(int x, int y)
{
    int result;
    result = x + y;
    return result;
}

// Calculation function
int doCalc()
{
    int val1{ 10 }, val2{ 20 };

    int* sampleHeapVariable = new int(20);

    int res = doAdd(val1, val2);

    delete sampleHeapVariable;

    return res;
}

int main()
{
    // CPU usage example
    double cpuUsage{ 72.5 };
    double& cpuRef{ cpuUsage };
    double* cpuPtr{ &cpuUsage };

    std::cout << "CPU Usage: " << cpuUsage << "\n";
    std::cout << "Through Reference: " << cpuRef << "\n";
    std::cout << "Through Pointer: " << *cpuPtr << "\n";

    updateUsage(cpuPtr);

    std::cout << "Updated CPU Usage: "
        << cpuUsage << "\n";

    // Dynamic memory example
    double* dynamicUsage{ new double{65.0} };

    std::cout << "Dynamic Value: "
        << *dynamicUsage << "\n";

    delete dynamicUsage;
    dynamicUsage = nullptr;

    // Create a StorageServer object
    StorageServer server(1000.0, 450.0);

    // Display initial storage
    server.displayStorage();

    // Update used storage
    server.updateUsedStorage(600.0);

    // Display updated storage
    server.displayStorage();

    // Call calculation function
    int x = doCalc();

    std::cout << "\nCalculation Result: " << x << "\n";

    return 0;
}