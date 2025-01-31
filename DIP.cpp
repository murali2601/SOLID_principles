/* Bad Example (Violating DIP)
Here, the EmailService class is directly referenced inside Notification.
If we want to change the notification method (e.g., use SMS instead of Email), we must modify Notification.
 */

/* #include <iostream>
using namespace std;

class EmailService {
public:
    void sendEmail(string message) {
        cout << "Sending Email: " << message << endl;
    }
};

class Notification {
private:
    EmailService emailService;  // Direct dependency on EmailService

public:
    void sendNotification(string message) {
        emailService.sendEmail(message);  // Hardcoded dependency
    }
};

int main() {
    Notification notifier;
    notifier.sendNotification("Hello, DIP is important!");  
    return 0;
}

 */
/*  Problems in This Code:

Tightly Coupled → Notification depends on EmailService, making changes difficult.
Hard to Extend → If we add SMS or WhatsApp notifications, we must modify Notification.
Violates DIP → High-level Notification directly depends on low-level EmailService.
 

Good Example (Following DIP)

To follow DIP, we introduce an interface (IMessageService), making Notification independent of any specific service.
 */

#include <iostream>
using namespace std;

// 1. Define an abstraction (interface)
class IMessageService {
public:
    virtual void sendMessage(string message) = 0;  // Pure virtual function
    virtual ~IMessageService() = default;
};

// 2. Implement concrete classes (Email & SMS)
class EmailService : public IMessageService {
public:
    void sendMessage(string message) override {
        cout << "Sending Email: " << message << endl;
    }
};

class SMSService : public IMessageService {
public:
    void sendMessage(string message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

// 3. High-level module (Notification) depends on abstraction, not concrete classes
class Notification {
private:
    IMessageService* service;  // Dependency Injection

public:
    Notification(IMessageService* svc) : service(svc) {}  // Constructor Injection

    void sendNotification(string message) {
        service->sendMessage(message);  // Calls dynamically bound method
    }
};

int main() {
    EmailService email;
    SMSService sms;

    Notification notifier1(&email);
    notifier1.sendNotification("Hello via Email!");  // ✅ Works with EmailService

    Notification notifier2(&sms);
    notifier2.sendNotification("Hello via SMS!");    // ✅ Works with SMSService

    return 0;
}
✅ Benefits of Following DIP:
Loose Coupling → Notification depends on an abstraction (IMessageService) rather than a concrete class.
Easily Extendable → We can add WhatsAppService, PushNotificationService, etc., without modifying Notification.
More Flexible → Any notification method can be injected at runtime