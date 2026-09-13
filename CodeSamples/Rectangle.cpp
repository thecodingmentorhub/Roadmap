#include <iostream>
#include "Rectangle.h"

double rectangle::area()
{
	return length * breadth;
}

rectangle::rectangle()	
{
	std::cout << "a rectangle object is created\n";
	length = 2;
	breadth = 5;
}