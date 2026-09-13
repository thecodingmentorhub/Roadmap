// 03_DeviceModelEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Server.h"

int main()
{
	Server s("sever01A", 67.5, 87);
	std::cout << s.getCpuUsage();
}

