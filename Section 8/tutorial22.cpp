#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> values {2, 5, 1, 3, 2, 6, 7};
    std::sort(values.begin(), values.end(), 
        [](int x, int y) {return x < y; });

    for (int value : values)
        std::cout << value << " ";
    std::cout << std::endl;

    std::vector<int> evens;
    copy_if(values.begin(), values.end(), back_inserter(evens),
        [](int x) { return x % 2 == 0; });

    for (int value : evens)
        std::cout << value << " ";
    std::cout << std::endl;

    int sum;
    std::for_each(values.begin(), values.end(), [&](int x) { sum += x; });

    std::cout << sum << std::endl;

    return 0;
}