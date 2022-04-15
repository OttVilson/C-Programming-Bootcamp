#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <cmath>
#include <vector>

bool IsPrime(unsigned int n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

std::vector<unsigned int> GatherPrimes(unsigned int from, unsigned int to) {
    std::vector<unsigned int> primes;
    for (unsigned int j = from; j <= to; j++)
        if (IsPrime(j))
            primes.push_back(j);

    return primes;
}

int main() {
    int startTime = clock();
    std::vector<unsigned int> primes = GatherPrimes(2, 100000);

    for (int j = primes.size() - 5; j < primes.size(); j++)
        std::cout << primes.at(j) << "\n";

    int endTime = clock();
    std::cout << "Execution time : " << (endTime - startTime) / double (CLOCKS_PER_SEC) << " seconds\n";

    return 0;
}