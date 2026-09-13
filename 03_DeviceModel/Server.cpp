#include "Server.h"

Server::Server(const std::string& serverName, double cpu, double memory)
	: name(serverName), cpuUsage(cpu), memoryUsage(memory)
{
}
const std::string& Server::getName() const
{
	return name;
}
double Server::getCpuUsage() const
{
	return cpuUsage;
}
double Server::getMemoryUsage() const
{
	return memoryUsage;
}
std::string Server::getStatus() const
{
	if (cpuUsage > 85 || memoryUsage > 85) return "Critical";
	if (cpuUsage >= 70 || memoryUsage >= 70) return "Warning";
	return "Healthy";
}