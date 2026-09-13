// 03_DeviceModel.cpp : Defines the functions for the static library.
//
#include <iostream>
#include "framework.h"
#include "Server.h"

// TODO: This is an example of a library function
void fnMy03DeviceModel()
{
	Server s("sever01A",67.5,87);
	std::cout << s.getCpuUsage();
}
