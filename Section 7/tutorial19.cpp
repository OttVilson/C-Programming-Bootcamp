#include <cstdlib>
#include <iostream>

void swap(int* array, int first, int second);

int main() {

    int length = 7;
    int numbers[length] = {2, 4, 3, 7, 1, 9, 5};

    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0; j--) {
            if (numbers[j] < numbers[j - 1]) {
                std::cout << numbers[j] << " is smaller than " << numbers[j - 1] << ". Swap!\n";
                swap(numbers, j, j - 1);
                for (int k = 0; k < length; k++) {
                    std::cout << numbers[k] << " ";
                }
                std::cout << "\n";
            } else break;
        }
    }

    return 0;
}

void swap(int* array, int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}