#include <iostream>
using namespace std;

class Addition {
    public:
        int add(int a, int b) {  
            return a + b;
        }
};
int main(){

    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    Addition obj;
    
    cout << "Sum: " << obj.add(num1, num2) << endl;
    return 0;
}