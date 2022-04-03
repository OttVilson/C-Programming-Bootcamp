#include <cstdlib>
#include <iostream>
#include <functional>
#include <vector>
#include <ctime>

std::vector<int> Filter(std::vector<int> vector, std::function<bool(int)> Predicate) {
    std::vector<int> results;
    for (int entry : vector)
        if (Predicate(entry))
            results.push_back(entry);

    return results;
}

bool IsOdd(int num) {
    return num % 2 != 0;
}

int CoinFlip() {
    return rand() % 2;
}

std::vector<int> GenerateRandomCoinFlips(int numberOfThrows) {
    srand(time(NULL));
    std::vector<int> results;
    for (int i = 0; i < numberOfThrows; i++) {
        results.push_back(CoinFlip());
    }

    return results;
}

int main() {
    std::vector<int> randomCoinFlips = GenerateRandomCoinFlips(100);
    std::vector<int> tails = Filter(randomCoinFlips, IsOdd);

    std::cout << "Out of 100 throws " << tails.size() << " are tails and the rest are heads." << std::endl;

    return 0;
}