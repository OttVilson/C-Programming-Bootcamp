#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int> Range(int start, int end, int step = 1);

int main() {

    double num1, num2;

    std::cout << "Enter numerator : ";
    std::cin >> num1;
    std::cout << "Enter denominator : ";
    std::cin >> num2;

    try {
        if (num2 == 0)
            throw "Division by Zero is not possible.";
        else
            printf("%.1f / %.1f = %.2f\n", num1, num2, num1 / num2);
    } catch (const char* error) {
        std::cout << "Error : " << error << std::endl;
    }

    try {
        std::cout << "Throwing Exception\n";
        throw std::runtime_error("Error occurred");
        std::cout << "Cant reach.\n";
    } 
    // catch(std::exception &exception) {
    //     std::cout << "Error : " << exception.what() << std::endl;
    // }

    catch(...) {
        std::cout << "Default exception catch.\n";
    }


    return 0;
}

std::vector<int> Range(int start, int max, int step) {
    std::vector<int> range;
    int i = start;
    while (i <= max) {
        range.push_back(i);
        i += step;
    }

    return range;
}