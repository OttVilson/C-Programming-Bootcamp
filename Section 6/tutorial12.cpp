#include <cstdlib>
#include <iostream>

void AssignAge(int* pAge, int age);

void DoubleValues(int *array, int size);

int main() {
    int age = 43;
    int *pAge = NULL;
    pAge = &age;
    
    std::cout << pAge << "\n";
    std::cout << *pAge << "\n";

    *pAge = 555;
    std::cout << *pAge << "\n";
    std::cout << age << "\n";

    AssignAge(&age, 23);
    std::cout << age << "\n";

    int intArray[] = {1, 2, 3};
    DoubleValues(intArray, 3);

    for (int i = 0; i < 3; i++) {
        std::cout << intArray[i] << "\n";
    }

    // int intArray[] = {9, 2, 3, 4};
    // int* pIntArray = intArray;

    // for (int i = 0; i < 20; i++) {
    //     std::cout << *pIntArray << "\n";
    //     pIntArray++;
    // }


    return 0;
}

void AssignAge(int* pAge, int age) {
    *pAge = age;
}

void DoubleValues(int *array, int size) {
    for (int i = 0; i < size; i++)
        array[i] *= 2;
}