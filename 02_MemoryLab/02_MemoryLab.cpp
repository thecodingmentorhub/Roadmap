#include <iostream>

void updateUsage(double* usage)
{
	if (usage != nullptr)
	{
		*usage = 88.0;
	}
}
int main_vere()
{
	double cpuUsage{ 72.5 };//variable
	double& cpuRef{ cpuUsage };//alias
	double* cpuPtr{ &cpuUsage };//pointer
	std::cout << cpuUsage << "\n"; //72.5
	std::cout << &cpuUsage << "\n"; //address-of cpuUsage
	std::cout << cpuRef<< "\n"; //72.5
	std::cout << &cpuRef << "\n"; //address-of cpuUsage
	std::cout << cpuPtr << "\n"; //address-of cpuUsage
	std::cout << *cpuPtr << "\n"; //72.5
	std::cout << &cpuPtr << "\n"; //address-of cpuPtr

	/*std::cout << "Value: " << cpuUsage << '\n';
	std::cout << "Through reference: " << cpuRef << '\n';
	std::cout << "Through pointer: " << *cpuPtr << '\n';*/
	
	updateUsage(cpuPtr);
	std::cout << "Updated: " << cpuUsage << '\n';
	double* dynamicUsage{ new double{65.0} };
	std::cout << "Dynamic value: " << *dynamicUsage << '\n';
	delete dynamicUsage;
	dynamicUsage = nullptr;
	return 0;
}

int doAdd(int x, int y)
{
	int result;
	result = x + y;
	return result;
}
int doCalc()
{
	int val1{ 10 }, val2{ 20 };
	int *sampleHeapVariable =  new int(20);
	int res = doAdd(val1, val2);
	delete sampleHeapVariable;	
	return res;
}

int main()
{
	int x = doCalc();
}