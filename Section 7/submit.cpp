#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>

std::vector<int> GenerateRandomVector(int numberOfNumbers, int minValue, int maxValue);

int main() {

    std::vector<int> randomInts = GenerateRandomVector(10, 5, 50);
    for (int integer : randomInts)
        std::cout << integer << "\n";

    return 0;
}

std::vector<int> GenerateRandomVector(int numberOfNumbers, int minValue, int maxValue) {
    std::vector<int> results;

    int range = maxValue + 1 - minValue;
    srand(time(NULL));
    int randomInt;

    for (int i = 0; i < numberOfNumbers; i++) {
        randomInt = rand() % range + minValue;
        results.push_back(randomInt);
    }

    return results;
}