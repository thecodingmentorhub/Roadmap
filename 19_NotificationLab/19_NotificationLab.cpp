#include <iostream>
#include <string>

// Abstract base class
class Notification
{
public:
    // Pure virtual function
    virtual void send() const = 0;

    // Virtual destructor
    virtual ~Notification() = default;
};

// Email notification
class EmailNotification : public Notification
{
public:
    void send() const override
    {
        std::cout << "Email: Sending notification through Email." << std::endl;
    }
};

// SMS notification
class SmsNotification : public Notification
{
public:
    void send() const override
    {
        std::cout << "SMS: Sending notification through SMS." << std::endl;
    }
};

// Push notification
class PushNotification : public Notification
{
public:
    void send() const override
    {
        std::cout << "Push: Sending notification through Push Notification." << std::endl;
    }
};

// Common delivery function
void deliver(const Notification& notification)
{
    notification.send();
}

int main()
{
    EmailNotification email;
    SmsNotification sms;
    PushNotification push;

    // Same deliver() function for all notification types
    deliver(email);
    deliver(sms);
    deliver(push);

    return 0;
}