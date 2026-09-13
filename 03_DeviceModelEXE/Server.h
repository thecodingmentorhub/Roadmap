#pragma once
#include <string>

class Server
{
public:
	Server(const std::string& name, double cpu, double memory);
	const std::string& getName() const;
	double getCpuUsage() const;
	double getMemoryUsage() const;
	std::string getStatus() const;
private:
	std::string name;
	double cpuUsage{};
	double memoryUsage{};
};