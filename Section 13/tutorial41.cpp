#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <thread>
#include <mutex>

bool IsPrime(unsigned int number) {
    for (int j = 2; j < number; j++)
        if (number % j == 0) return false;

    return true;
}

std::mutex vectLock;
std::vector<unsigned int> primes;

void PushIfPrime(unsigned int number) {
    if (IsPrime(number)) {
        vectLock.lock();
        primes.push_back(number);
        vectLock.unlock();
    }
}

void FindPrimes(unsigned int start, unsigned int stop) {
    for (unsigned int i = start; i <= stop; i++)
        PushIfPrime(i);
}

void FindPrimesWithThreads(unsigned int start, unsigned int end, 
        unsigned int numberOfThreads) {
    std::vector<std::thread> threadVect;
    unsigned int threadSpread = end / numberOfThreads;
    unsigned int newEnd = start + threadSpread - 1;
    for (unsigned int x = 0; x < numberOfThreads; x++) {
        threadVect.emplace_back(FindPrimes, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }
    for (auto& t : threadVect) {
        t.join();
    }
}

int main() {
    int start = clock();

    FindPrimesWithThreads(2, 100000, 3);

    int stop = clock();
    std::cout << "The process took " << (stop - start) / double (CLOCKS_PER_SEC) << " seconds.\n";

    std::cout << "Number of primes is " << primes.size() << "\n";
}