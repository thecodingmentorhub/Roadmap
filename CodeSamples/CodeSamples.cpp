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

void main()
{
	vehicle activa;
	activa.set(150.45, 85);
	activa.show();

	car beat;
	beat.set(987.99, 160);
	beat.show();
}