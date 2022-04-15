#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <ctime>

int GetRandom(int maxValue) {
    srand(time(NULL));
    return rand() % (maxValue + 1);
}

void ExecuteThread(int id) {
    auto nowTime = std::chrono::system_clock::now();
    time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    tm myLocalTime = *localtime(&sleepTime);
    std::cout << "Thread " << id << " Sleep time : " << ctime(&sleepTime);
    std::cout << "Month : " << myLocalTime.tm_mon << "\n";
    std::cout << "Day : " << myLocalTime.tm_mday << "\n";
    std::cout << "Year : " << myLocalTime.tm_year << "\n";
    std::cout << "Hours : " << myLocalTime.tm_hour << "\n";
    std::cout << "Minutes : " << myLocalTime.tm_min << "\n";
    std::cout << "Seconds : " << myLocalTime.tm_sec << "\n";

    std::this_thread::sleep_for (std::chrono::seconds(GetRandom(3)));
    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    std::cout << "Thread " << id << " Awake Time : " << ctime(&sleepTime) << std::endl;
}

double accountBalance = 100;

std::mutex accountLock;

std::string GetTime() {
    auto nowTime = std::chrono::system_clock::now();
    time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    return ctime(&sleepTime);
}

void GetMoney(int id, double withdrawal) {
    std::lock_guard<std::mutex> lock(accountLock);
    // accountLock.lock();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << id << " tries to withdraw $" << withdrawal << " on " <<
        GetTime() << std::endl;

    if (accountBalance >= withdrawal) {
        accountBalance -= withdrawal;
        std::cout << "The new balance is " << accountBalance << std::endl;
    } else {
        std::cout << "Not enough money on the account.\n";
        std::cout << "Current balance $" << accountBalance << "\n";
    }

    // accountLock.unlock();
}

int main() {

    std::thread threadPool[10];
    for (int i = 0; i < 10; i++) {
        threadPool[i] = std::thread(GetMoney, i, 15);
    }

    for (int i = 0; i < 10; i++) {
        threadPool[i].join();
    }

    // std::thread th1 (ExecuteThread, 1);
    // std::thread th2 (ExecuteThread, 2);
    // th1.join();
    // th2.join();
    return 0;
}