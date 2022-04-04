#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <vector>

typedef std::vector<int> intVec;

int main() {
    int amtToStore;
    std::cout << "How many numbers to you want to store : ";
    std::cin >> amtToStore;

    int * pNums;
    pNums = (int*) malloc(amtToStore * sizeof(int));
    if (pNums != NULL) {
        int i = 0;
        while (i < amtToStore) {
            std::cout << "Enter a Number : ";
            std::cin >> pNums[i];
            i++; 
        }

        std::cout << "You entered these Numbers" << "\n";
        for (int i = 0; i < amtToStore; i++) {
            std::cout << pNums[i] << "\n";
        }

        delete pNums;
    }

    std::cout << "How many ints to you want to store : ";
    std::cin >> amtToStore;
    
    std::unique_ptr<int[]> pNumsU (new int[amtToStore]);
    if (pNumsU != NULL) {
        int toEnter;
        for (int i = 0; i < amtToStore; i++) {
            std::cout << "Enter number : ";
            std::cin >> toEnter;
            pNumsU[i] = toEnter;
        }
        
        std::cout << "You entered the numbers : ";
        for(int i = 0; i < amtToStore; i++) {
            std::cout << pNumsU[i] << " ";
        }
        std::cout << "\n";
    }

    // intVec vector {1, 2, 4, 7};
    // std::cout << vector.size() << "\n";
    // for (int number : vector)
    //     std::cout << number << " ";
    // std::cout << "\n";

    // std::cout << "Tere\n";

    return 0;
}