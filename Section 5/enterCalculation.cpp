#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

int main() {

    std::string expression;
    std::cout << "Enter calculation with spaces inbetween (e.g. 6 + 5) : ";
    getline(std::cin, expression);

    char space = ' ';
    std::stringstream ss(expression);

    std::vector<double> numbers;
    std::vector<std::string> operations;

    std::string input;
    int counter = 0;
    while (getline(ss, input, space)) {
        if (counter % 2 == 0)
            numbers.push_back(stod(input));
        else
            operations.push_back(input);
        counter++;
    }

    double total = numbers[0];
    for (int i = 0; i < operations.size(); i++) {
        std::string operation = operations[i];
        double next = numbers[i + 1];
        if (operation == "+") total += next;
        else if (operation == "-") total -= next;
        else if (operation == "*") total *= next;
        else if (operation == "/") total /= next;
        printf("Next : %.2f, total : %.2f, operation: %s.\n", next, total, operation.c_str());
    }
    
    std::cout << total << "\n";
    return 0;
}