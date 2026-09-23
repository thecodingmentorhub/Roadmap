#include <iostream>
#include <string>

namespace NotificationSystem
{
    // Interface-like abstract class
    class INotification
    {
    public:
        // Pure virtual function
        virtual void send(const std::string& message) = 0;

        // Virtual destructor
        virtual ~INotification() = default;
    };


    // Email notification
    class Email : public INotification
    {
    private:
        std::string emailAddress;

    public:
        // Constructor
        explicit Email(const std::string& address)
            : emailAddress(address)
        {
        }

        // Function overriding
        void send(const std::string& message) override
        {
            std::cout << "\n--- Email Notification ---" << std::endl;
            std::cout << "To      : " << emailAddress << std::endl;
            std::cout << "Message : " << message << std::endl;
        }
    };


    // SMS notification
    class SMS : public INotification
    {
    private:
        std::string phoneNumber;

    public:
        // Constructor
        explicit SMS(const std::string& number)
            : phoneNumber(number)
        {
        }

        // Function overriding
        void send(const std::string& message) override
        {
            std::cout << "\n--- SMS Notification ---" << std::endl;
            std::cout << "To      : " << phoneNumber << std::endl;
            std::cout << "Message : " << message << std::endl;
        }
    };


    // Console notification
    class Console : public INotification
    {
    private:
        std::string applicationName;

    public:
        // Constructor
        explicit Console(const std::string& application)
            : applicationName(application)
        {
        }

        // Function overriding
        void send(const std::string& message) override
        {
            std::cout << "\n--- Console Notification ---" << std::endl;
            std::cout << "Application : " << applicationName << std::endl;
            std::cout << "Message     : " << message << std::endl;
        }
    };


    // Common notification function
    void notifyUser(
        INotification& notification,
        const std::string& message)
    {
        notification.send(message);
    }
}


int main()
{
    using namespace NotificationSystem;

    std::string emailAddress;
    std::string phoneNumber;
    std::string applicationName;
    std::string message;

    int choice = 0;

    std::cout << "====================================" << std::endl;
    std::cout << "       Notification System" << std::endl;
    std::cout << "====================================" << std::endl;

    // Select notification type
    std::cout << "\nSelect Notification Type:" << std::endl;
    std::cout << "1. Email" << std::endl;
    std::cout << "2. SMS" << std::endl;
    std::cout << "3. Console" << std::endl;

    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    // Remove newline from input buffer
    std::cin.ignore();

    // Get notification message
    std::cout << "Enter notification message: ";
    std::getline(std::cin, message);


    if (choice == 1)
    {
        std::cout << "Enter email address: ";
        std::getline(std::cin, emailAddress);

        Email email(emailAddress);

        // Runtime polymorphism
        notifyUser(email, message);
    }
    else if (choice == 2)
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);

        SMS sms(phoneNumber);

        // Runtime polymorphism
        notifyUser(sms, message);
    }
    else if (choice == 3)
    {
        std::cout << "Enter application name: ";
        std::getline(std::cin, applicationName);

        Console console(applicationName);

        // Runtime polymorphism
        notifyUser(console, message);
    }
    else
    {
        std::cout << "\nInvalid notification type." << std::endl;
    }


    std::cout << "\n====================================" << std::endl;
    std::cout << "        Program Completed" << std::endl;
    std::cout << "====================================" << std::endl;

    return 0;
}