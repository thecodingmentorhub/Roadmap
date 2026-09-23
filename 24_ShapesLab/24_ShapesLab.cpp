#include <iostream>
#include <string>

// --------------------------------------------------
// Base Class: Shape
// --------------------------------------------------
class Shape
{
public:
    virtual void draw() const
    {
        std::cout << "Drawing shape\n";
    }

    virtual ~Shape() = default;
};

// --------------------------------------------------
// Derived Class: Circle
// --------------------------------------------------
class Circle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing circle\n";
    }
};

// --------------------------------------------------
// Derived Class: Rectangle
// --------------------------------------------------
class Rectangle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing rectangle\n";
    }
};

// --------------------------------------------------
// Draw any Shape
// --------------------------------------------------
void drawShape(const Shape& shape)
{
    shape.draw();
}

// --------------------------------------------------
// Main
// --------------------------------------------------
int main()
{
    std::cout << "SHAPES LAB\n";
    std::cout << "--------------------------------\n";

    Circle circle;
    Rectangle rectangle;
    Shape shape;

    std::cout << "\nDrawing individual objects:\n";

    shape.draw();
    circle.draw();
    rectangle.draw();

    std::cout << "\nDrawing through drawShape():\n";

    drawShape(circle);
    drawShape(rectangle);
    drawShape(shape);

    return 0;
}