#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// ======================
// User Class
// ======================
class User {
private:
    std::string username;
    std::string password;

public:
    // Constructor
    User(const std::string &uname, const std::string &pwd)
        : username(uname), password(pwd) {}

    // Getters
    std::string getUsername() const {
        return username;
    }

    std::string getPassword() const {
        return password;
    }

    // Setters
    void setUsername(const std::string &uname) {
        username = uname;
    }

    void setPassword(const std::string &pwd) {
        password = pwd;
    }
};

// ======================
// LoginRegistration Class
// ======================
class LoginRegistration {
private:
    std::vector<User> registeredUsers;  // Stores all registered users

public:
    // Method to register a new user
    bool registerUser(const std::string &uname, const std::string &pwd) {
        // Check if user already exists
        for (const auto &user : registeredUsers) {
            if (user.getUsername() == uname) {
                std::cout << "Registration failed: Username already exists.\n";
                return false;
            }
        }
        // Create and add new user
        User newUser(uname, pwd);
        registeredUsers.push_back(newUser);
        std::cout << "Registration successful for user: " << uname << std::endl;
        return true;
    }

    // Method to login an existing user
    bool loginUser(const std::string &uname, const std::string &pwd) {
        // Search for the user in the registered list
        for (const auto &user : registeredUsers) {
            if (user.getUsername() == uname && user.getPassword() == pwd) {
                std::cout << "Login successful. Welcome, " << uname << "!\n";
                return true;
            }
        }
        std::cout << "Login failed: Invalid username or password.\n";
        return false;
    }

    // Optional: Display all registered users (for debugging/demo)
    void displayAllUsers() {
        std::cout << "\n=== Registered Users ===\n";
        for (const auto &user : registeredUsers) {
            std::cout << "- " << user.getUsername() << "\n";
        }
        std::cout << "========================\n\n";
    }
};

// ======================
// Dummy Event Class (Placeholder for a larger Event component)
// ======================
class Event {
private:
    std::string eventName;
    std::string eventId;

public:
    Event(const std::string &id, const std::string &name)
        : eventId(id), eventName(name) {}

    std::string getEventId() const {
        return eventId;
    }

    std::string getEventName() const {
        return eventName;
    }

    void setEventName(const std::string &name) {
        eventName = name;
    }
};

// ======================
// Organizer Class
// ======================
class Organizer {
private:
    std::string organizerName;
    std::string organizerId;
    std::vector<Event> managedEvents;  // The events managed by this organizer

public:
    // Constructor
    Organizer(const std::string &orgId, const std::string &orgName)
        : organizerId(orgId), organizerName(orgName) {}

    // Add an event to the organizer's list
    void addEvent(const Event &ev) {
        managedEvents.push_back(ev);
        std::cout << "Event '" << ev.getEventName() 
                  << "' added by Organizer: " << organizerName << std::endl;
    }

    // Remove an event (by event ID) from the organizer's list
    void removeEvent(const std::string &eventId) {
        // Find event in the vector
        auto it = std::remove_if(managedEvents.begin(), managedEvents.end(),
            [&eventId](const Event &ev) {
                return ev.getEventId() == eventId;
            });

        if (it != managedEvents.end()) {
            std::cout << "Removing event with ID " << eventId 
                      << " from Organizer: " << organizerName << std::endl;
            managedEvents.erase(it, managedEvents.end());
        } else {
            std::cout << "Event with ID " << eventId 
                      << " not found under Organizer: " << organizerName << std::endl;
        }
    }

    // Display the events managed by this organizer
    void displayManagedEvents() const {
        std::cout << "\nOrganizer: " << organizerName 
                  << " (ID: " << organizerId << ") manages these events:\n";
        if (managedEvents.empty()) {
            std::cout << "  No events currently managed.\n";
            return;
        }
        for (const auto &ev : managedEvents) {
            std::cout << "  - " << ev.getEventName() << " (ID: " 
                      << ev.getEventId() << ")\n";
        }
        std::cout << std::endl;
    }
};

// ======================
// Main Function (Demo)
// ======================
int main() {
    // Instantiate the LoginRegistration system
    LoginRegistration lrSystem;

    // Register some users
    lrSystem.registerUser("alice", "password123");
    lrSystem.registerUser("bob", "bobpass");
    lrSystem.registerUser("alice", "newpass");  // Trying duplicate registration

    // Display all users (for demo)
    lrSystem.displayAllUsers();

    // Attempt user logins
    lrSystem.loginUser("alice", "wrongpass");
    lrSystem.loginUser("bob", "bobpass");

    // Create an Organizer
    Organizer organizer1("ORG01", "Carl");

    // Create some dummy events
    Event event1("E100", "Tech Talk");
    Event event2("E101", "Coding Workshop");

    // Organizer adds events
    organizer1.addEvent(event1);
    organizer1.addEvent(event2);

    organizer1.displayManagedEvents();

    // Remove an event
    organizer1.removeEvent("E100");
    organizer1.displayManagedEvents();

    // Try removing a non-existent event
    organizer1.removeEvent("E999");

    return 0;
}
