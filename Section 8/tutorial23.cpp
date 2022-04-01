#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

std::vector<int> GenerateFibonacciList(int maxNumber);

int main() {
    std::vector<int> fibs = GenerateFibonacciList(35);
    for (int value : fibs)
        std::cout << value << " ";
    std::cout << std::endl;

    int denominator = 3; 
    std::vector<int> values {3, 5, 6, 9, 14, 17, 7, 12};

    std::vector<int> dividables;
    copy_if(values.begin(), values.end(), back_inserter(dividables), 
        [denominator](int x) { return x % denominator == 0; });

    for (int value : dividables)
        std::cout << value << " ";
    std::cout << std::endl;

    std::vector<int> multiplied;
    std::transform(values.begin(), values.end(), back_inserter(multiplied), 
        [](int x) { return x * 2; });

    for (int value : multiplied)
        std::cout << value << " ";
    std::cout << std::endl;

    std::function<int(int)> Fib = [&Fib](int N) {
        if (N < 2) return N;
        else return Fib(N - 1) + Fib(N - 2);
    };

    std::cout << "Fibonacci of 5 = " << Fib(5) << std::endl;

    return 0;
}

std::vector<int> GenerateFibonacciList(int maxNumber) {
    std::vector<int> result;

    std::function<int(int)> Fibonacci = [&Fibonacci](int N) {
        return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
    };

    int fibonacciNumber = 0;
    while (fibonacciNumber <= maxNumber) {
        result.push_back(fibonacciNumber);
        fibonacciNumber = Fibonacci(result.size());
    }

    return result;
}
