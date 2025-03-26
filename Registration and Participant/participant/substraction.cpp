#include <iostream>

int main() {
    int num1, num2;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    int result = num1 - num2;
    std::cout << "Result of subtraction: " << result << std::endl;

    return 0;
}
