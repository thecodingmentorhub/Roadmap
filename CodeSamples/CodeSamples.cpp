#include <iostream>
class vehicle
{
	double enginecap;
	double topspeed;
public:
	void set(double ec, double ts)
	{
		enginecap = ec;
		topspeed = ts;
	}
	void show()
	{
		std::cout << enginecap << "\n";
		std::cout << topspeed << "\n";
	}
};

/*
class <child> : <inheritance-access> <parent>
{};
*/

class car : public vehicle
{ };

class suziki : public car
{ };

class volkswagen : car
{
};

class Math
{
public:
	int add(int a, int b)
	{
		return a + b;
	}
	int add(int a, int b, int c)
	{
		return a + b + c;
	}
};

class SMath : public Math
{
public:
	std::string add(std::string s1, std::string s2)
	{
		return s1 + s2;
	}
};

void main()
{
	Math s1;
	std::cout << s1.add(10, 20) << "\n";
	std::cout << s1.add(10, 20, 30) << "\n";

	SMath sM1;
	std::cout << sM1.add("hello", "world") << "\n";
}