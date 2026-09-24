// AbstractClassLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Abstract base class
class Document
{
public:
    // Pure virtual function
    virtual void print() const = 0;

    // Virtual destructor
    virtual ~Document() = default;
};

// Derived class
class PdfDocument : public Document
{
public:
    void print() const override
    {
        cout << "Printing PDF document" << endl;
    }
};

// Derived class
class TextDocument : public Document
{
public:
    void print() const override
    {
        cout << "Printing Text document" << endl;
    }
};

// Common function for all Document types
void printDocument(const Document& document)
{
    document.print();
}

int main()
{
    PdfDocument pdf;
    TextDocument text;

    // Process different documents through Document&
    printDocument(pdf);
    printDocument(text);

    // Uncomment this line to test the abstract class:
    // Document d;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
