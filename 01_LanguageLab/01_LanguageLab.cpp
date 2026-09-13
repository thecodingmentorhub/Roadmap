#include <iomanip>
#include <iostream>
#include <string>
double readValidUsage(int readingNumber);
std::string getStatus(double usage);

void updateCounters(
	const std::string& status,
	int& healthyCount,
	int& warningCount,
	int& criticalCount);

void updateMinMax(
	double usage,
	double& lowest,
	double& highest);

double calculateAverage(double total, int count);
void displaySummary(
	const std::string& serverName,
	int readingCount,
	int healthyCount,
	int warningCount,
	int criticalCount,
	double averageUsage,
	double lowestUsage,
	double highestUsage);

int main()
{
	std::string serverName;
	double cpuReadings[5]{};
	std::cout << "SYSTEM MONITORING APPLICATION\n";
	std::cout << "--------------------------------\n";
	std::cout << "Enter server name: ";
	std::cin >> serverName;
	for (int index{ 0 }; index < 5; index++)
	{
		cpuReadings[index] = readValidUsage(index + 1);
	}
	int healthyCount{};
	int warningCount{};
	int criticalCount{};
	double totalUsage{};
	double lowestUsage{ cpuReadings[0] };
	double highestUsage{ cpuReadings[0] };
	std::cout << "\nREADING ANALYSIS\n";
	std::cout << "--------------------------------\n";
	for (int index{ 0 }; index < 5; index++)
	{
		double cpuUsage{ cpuReadings[index] };
		totalUsage += cpuUsage;
		updateMinMax(cpuUsage, lowestUsage, highestUsage);
		std::string status{ getStatus(cpuUsage) };
		updateCounters(
			status,
			healthyCount,
			warningCount,
			criticalCount);
		std::cout << "Reading " << index + 1
			<< ": " << cpuUsage
			<< "% - " << status << '\n';
	}
	double averageUsage{
	calculateAverage(totalUsage, 5)
	};
	displaySummary(
		serverName,
		5,
		healthyCount,
		warningCount,
		criticalCount,
		averageUsage,
		lowestUsage,
		highestUsage);
	return 0;
}
double readValidUsage(int readingNumber)//stack contains param, and local variables. readingNumber and usage
{
	double usage{};
	std::cout << "Enter CPU reading "
		<< readingNumber << ": ";
	std::cin >> usage;
	while (usage < 0 || usage > 100)
	{
		std::cout << "Invalid CPU usage. Enter again: ";
		std::cin >> usage;
	}
	return usage;
}
std::string getStatus(double usage)
{
	if (usage > 85)
	{
		return "Critical";
	}
	if (usage >= 70)
	{
		return "Warning";
	}
	return "Healthy";
}
void updateCounters(
	const std::string& status,
	int& healthyCount,
	int& warningCount,
	int& criticalCount)
{
	if (status == "Critical")
	{
		criticalCount++;
	}
	else if (status == "Warning")
	{
		warningCount++;
	}
	else
	{
		healthyCount++;
	}
}
void updateMinMax(
	double usage,
	double& lowest,
	double& highest)
{
	if (usage < lowest)
	{
		lowest = usage;
	}
	if (usage > highest)
	{
		highest = usage;
	}
}
double calculateAverage(double total, int count)
{
	return total / count;
}
void displaySummary(
	const std::string& serverName,
	int readingCount,
	int healthyCount,
	int warningCount,
	int criticalCount,
	double averageUsage,
	double lowestUsage,
	double highestUsage)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nMONITORING SUMMARY\n";
	std::cout << "--------------------------------\n";
	std::cout << "Server : " << serverName << '\n';
	std::cout << "Total Readings : " << readingCount << '\n';
	std::cout << "Healthy : " << healthyCount << '\n';
	std::cout << "Warning : " << warningCount << '\n';
	std::cout << "Critical : " << criticalCount << '\n';
	std::cout << "Average CPU : " << averageUsage << "%\n";
	std::cout << "Highest CPU : " << highestUsage << "%\n";
	std::cout << "Lowest CPU : " << lowestUsage << "%\n";
}