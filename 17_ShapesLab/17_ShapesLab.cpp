
#include <iostream>

class Shape
{
public:
    virtual double area() const = 0;

    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
    double width;
    double height;

public:
    Rectangle(double w, double h)
        : width{ w }, height{ h }
    {
    }

    double area() const override
    {
        return width * height;
    }
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double r)
        : radius{ r }
    {
    }

    double area() const override
    {
        constexpr double pi{ 3.14159 };
        return pi * radius * radius;
    }
};

void printArea(const Shape& shape)
{
    std::cout << "Area: " << shape.area() << '\n';
}

int main()
{
    // Object creation
    Rectangle rectangle{ 10.0, 5.0 };
    Circle circle{ 7.0 };

    // Same function
    printArea(rectangle);
    printArea(circle);

    // Base class reference
    Shape& shapeRef{ rectangle };
    printArea(shapeRef);

    shapeRef = circle; // Does NOT change the referred object
    // (reference cannot be reseated)

// Base class pointer
    Shape* shapePtr{ &rectangle };
    printArea(*shapePtr);

    shapePtr = &circle;
    printArea(*shapePtr);

    return 0;
}