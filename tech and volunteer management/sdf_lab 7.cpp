#include <iostream>
using namespace std;

// Volunteer Class
class Volunteer{
public:
    int id;
    string name;
    string contact;
    string role;
    string experience;

    void setDetails(int v_id, string v_name, string v_contact, string v_role, string v_experience){
        id = v_id;
        name = v_name;
        contact = v_contact;
        role = v_role;
        experience = v_experience;
    }

    void display(){
        cout << id << " , " << name << " , " << contact << " , " << role << " , " << experience << endl;
    }
};

int main() {
    Volunteer v1, v2, v3;

    v1.setDetails(1, "Rohan", "9876543210", "Registration", "Intermediate");
    v2.setDetails(2, "Rahul", "9123456789", "Security", "Experienced");
    v3.setDetails(3, "Shiva", "9568713556", "Logistics", "Beginner");

    cout << "Volunteer Details :"<<endl;
    
    v1.display();
    v2.display();
    v3.display();

    return 0;
}
