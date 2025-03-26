#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Dummy Class: Participant (from Participant Management Component)
class Participant {
public:
    int participantID;
    string name;
    Participant(int id, string n) : participantID(id), name(n) {}
};

// Dummy Class: Volunteer (from Volunteer Management Component)
class Volunteer {
public:
    int volunteerID;
    string name;
    Volunteer(int id, string n) : volunteerID(id), name(n) {}
};

// Dummy Class: Vendor (from Vendor & Sponsor Management Component)
class Vendor {
public:
    int vendorID;
    string vendorName;
    Vendor(int id, string name) : vendorID(id), vendorName(name) {}
};

// Primary Class: Employee Management
class Employee {
public:
    int employeeID;
    string employeeName;
    string role;
    Employee(int id, string name, string r) : employeeID(id), employeeName(name), role(r) {}
};

class EmployeeManager {
public:
    vector<Employee> employees;

    void addEmployee(Employee employee) {
        employees.push_back(employee);
        cout << "Employee Added: " << employee.employeeName << " - " << employee.role << endl;
    }

    void listEmployees() {
        cout << "Employee List:" << endl;
        for (const auto& e : employees) {
            cout << "ID: " << e.employeeID << ", Name: " << e.employeeName << ", Role: " << e.role << endl;
        }
    }
};

// Primary Class: Event
class Event {
public:
    int eventID;
    string eventName;
    string eventDate;
    int venueID;
    Event(int id, string name, string date, int venue) : eventID(id), eventName(name), eventDate(date), venueID(venue) {}
};

// Primary Class: Venue
class Venue {
public:
    int venueID;
    string venueName;
    int capacity;
    Venue(int id, string name, int cap) : venueID(id), venueName(name), capacity(cap) {}
};

// Class: EventScheduler
class EventScheduler {
public:
    vector<Event> events;
    vector<Venue> venues;

    void addVenue(Venue venue) {
        venues.push_back(venue);
    }

    void scheduleEvent(Event event) {
        // Check for venue availability
        for (const auto& v : venues) {
            if (v.venueID == event.venueID) {
                events.push_back(event);
                cout << "Event: " << event.eventName << " scheduled at " << v.venueName << " on " << event.eventDate << endl;
                return;
            }
        }
        cout << "Venue not found for Event: " << event.eventName << endl;
    }
};

// Main Function for Testing
int main() {
    EventScheduler scheduler;
    EmployeeManager employeeManager;

    // Add Venues
    scheduler.addVenue(Venue(1, "Auditorium A", 500));
    scheduler.addVenue(Venue(2, "Open Ground B", 2000));

    // Add Employees
    employeeManager.addEmployee(Employee(1, "John Doe", "Event Manager"));
    employeeManager.addEmployee(Employee(2, "Jane Smith", "Coordinator"));

    // List Employees
    employeeManager.listEmployees();

    // Schedule Events
    scheduler.scheduleEvent(Event(101, "Tech Talk", "2025-05-12", 1));
    scheduler.scheduleEvent(Event(102, "Cultural Dance", "2025-05-13", 2));

    return 0;
}
