#include <cstdlib>
#include <iostream>

double AddNumbers(int num1 = 0, int num2 = 0);

void AssignAge(int age);

int AssignAge();

int main() {

    double num1, num2;
    std::cout << "Enter number 1 : ";
    std::cin >> num1;
    std::cout << "Enter number 2 : ";
    std::cin >> num2;

    printf("%.1f + %.1f = %.1f\n", num1, num2, AddNumbers(num1));

    int age = 43;
    AssignAge(24);
    std::cout << age << "\n";

    return 0;
}

double AddNumbers(int num1, int num2) {
    return num1 + num2 * 2;
}

void AssignAge(int age) {
    age = 24;
}

int AssignAge() {
    return 24;
}