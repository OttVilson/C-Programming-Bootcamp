#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>

bool IsPrime(int number);
std::vector<int> GetPrimes(int upToNumber);
std::vector<int> GenerateRandomVector(int numberOfNumbers, int minValue, int maxValue);

int main() {

    int number;
    std::cout << "Enter a possible prime to be checked : ";
    std::cin >> number;
    std::cout << "The number " << number << " is" << (IsPrime(number) ? "" : "n't") << " prime.\n";

    std::vector<int> primes = GetPrimes(2);
    for (int prime : primes)
        std::cout << prime << "\n";

    std::vector<int> randomInts = GenerateRandomVector(1, 3, 9);
    for (int integer : randomInts)
        std::cout << integer << "\n";

    return 0;
}

bool IsPrime(int number) {
    double sqrtOfNumber = sqrt(number);

    int currentDivider = 2;
    while (currentDivider <= sqrtOfNumber)
        if (number % currentDivider++ == 0) return false;

    return true;
}

std::vector<int> GetPrimes(int upToNumber) {
    std::vector<int> results;
    int currentNumber = 2;
    while (currentNumber <= upToNumber) {
        if (IsPrime(currentNumber))
            results.push_back(currentNumber);
        currentNumber++;
    }

    return results;
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