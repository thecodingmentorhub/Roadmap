#include <iostream>
#include <string>

class Book
{
    std::string title;
    std::string author;
    bool available;

public:
    Book(const std::string& bookTitle, const std::string& bookAuthor)
        : title{ bookTitle }, author{ bookAuthor }, available{ true }
    {
    }

    void borrowBook()
    {
        if (available)
        {
            available = false;

            std::cout << title
                << " has been borrowed.\n";
        }
        else
        {
            std::cout << title
                << " is already borrowed.\n";
        }
    }

    void returnBook()
    {
        if (!available)
        {
            available = true;

            std::cout << title
                << " has been returned.\n";
        }
        else
        {
            std::cout << title
                << " is already available.\n";
        }
    }

    bool isAvailable() const
    {
        return available;
    }
};


int main()
{
    std::cout << "LIBRARY BOOK APPLICATION\n";
    std::cout << "--------------------------------\n";

    // Two independent Book objects
    Book book1{
        "The C++ Programming Language",
        "Bjarne Stroustrup"
    };

    Book book2{
        "Clean Code",
        "Robert C. Martin"
    };


    // Check initial availability
    std::cout << "\nINITIAL STATUS\n";
    std::cout << "--------------------------------\n";

    std::cout << "Book 1 available: "
        << std::boolalpha
        << book1.isAvailable()
        << '\n';

    std::cout << "Book 2 available: "
        << book2.isAvailable()
        << '\n';


    // Borrow book1
    std::cout << "\nBORROW BOOK 1\n";
    std::cout << "--------------------------------\n";

    book1.borrowBook();

    // Try borrowing the same book again
    book1.borrowBook();


    // Return book1
    std::cout << "\nRETURN BOOK 1\n";
    std::cout << "--------------------------------\n";

    book1.returnBook();


    // Borrow book2 independently
    std::cout << "\nBORROW BOOK 2\n";
    std::cout << "--------------------------------\n";

    book2.borrowBook();


    // Final status
    std::cout << "\nFINAL STATUS\n";
    std::cout << "--------------------------------\n";

    std::cout << "Book 1 available: "
        << book1.isAvailable()
        << '\n';

    std::cout << "Book 2 available: "
        << book2.isAvailable()
        << '\n';


    return 0;
}