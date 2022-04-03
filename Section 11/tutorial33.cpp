#include <cstdlib>
#include <iostream>
#include <functional>
#include <vector>
#include <ctime>

double MultByTwo(double num, double otherNum) {
    return num * 2 + otherNum;
}

double DoMath(std::function<double(double, double)> func, double num, double otherNum) {
    return func(num, otherNum) * func(num, otherNum);
}

double MultBy3(double num) {
    return num * 3;
}

double MultBy4(double num) {
    return num * 4;
}

double DoHeavyMath(std::vector<std::function<double(double)>> funcs, double num) {
    for (std::function<double(double)> func : funcs)
        num = func(num);

    return num;
}

std::function<double(double)> DoHeavyMathAndReturnFunction(std::vector<std::function<double(double)>> funcs) {
    return [funcs](double num) {
        for (std::function<double(double)> func : funcs)
            num = func(num);

        return num;
    };    
}

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

    std::function<double(double, double)> byTwo = MultByTwo;

    std::cout << "5 * 2 + 4= " << MultByTwo(5, 4) << std::endl;
    std::cout << "(4 * 2 + 3)^2 = " << DoMath(byTwo, 4, 3) << std::endl;

    std::vector<std::function<double(double)>> funcs;
    funcs.push_back(MultBy3);
    funcs.push_back(MultBy4);

    std::cout << "2 * 3 * 4 = " << DoHeavyMath(funcs, 2) << std::endl;

    std::function<double(double)> compositionFunc = DoHeavyMathAndReturnFunction(funcs);
    std::cout << "5 * 3 * 4 = " << compositionFunc(5) << std::endl;

    std::vector<int> original {1, 2, 4, 5, 6, 7, 9, 11, 12};
    std::vector<int> odd = Filter(original, IsOdd);
    for (int entry : odd)
        std::cout << entry << "\n";

    std::vector<int> randomCoinFlips = GenerateRandomCoinFlips(100);
    std::vector<int> tails = Filter(randomCoinFlips, IsOdd);

    std::cout << "Out of 100 throws " << tails.size() << " are tails and the rest are heads." << std::endl;

    return 0;
}