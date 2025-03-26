#include <iostream>
#include <string>
using namespace std;

// Multiplication for integers and strings
int multiply(int a, int b)
{
    return a * b;
}

string multiply(string a, int times)
{
    string result = "";
    for (int i = 0; i < times; i++)
    {
        result += a;
    }
    return result;
}

int main()
{

    cout << "Multiplication of 5 and 3: " << multiply(5, 3) << endl;

    cout << "String Multiplication: abs * 2 = " << multiply("abs", 2) << endl;

    return 0;
}
