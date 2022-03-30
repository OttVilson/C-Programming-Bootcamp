#include <cstdlib>
#include <iostream>
#include <array>

int main() {

    int arr[10] = {1};

    std::cout << arr[6] << "\n";
    std::cout << arr[12] << "\n"; 
 
    std::cout << arr[0] << "\n";
    arr[0] = 7;
    std::cout << arr[0] << "\n";

    std::cout << "Size is : " << sizeof(arr) / sizeof(*arr) << "\n";

    std::array<int, 5> arrayObject = {9, 8, 7, 6};

    for (auto j = arrayObject.begin(); j != arrayObject.end(); j++)
        std::cout << " " << *j ;

    std::cout << "\n" << "Size : " << arrayObject.size() << std::endl;
    std::cout << "Max size : " << arrayObject.max_size() << std::endl;

    if (!arrayObject.empty())
        std::cout << arrayObject[0] << std::endl;

    std::cout << arrayObject.at(0) << std::endl;

    std::array<int, 5> toSwap;
    toSwap.fill(3);
    toSwap.swap(arrayObject);

    std::cout << "arrayObject\n";
    for (int i = 0; i < 5; i++)
        std::cout << arrayObject[i] << " ";

    std::cout << "\ntoSwap\n";
    for (int i = 0; i < 5; i++)
        std::cout << toSwap[i] << " ";

    int multi[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    std::cout << "\nmulti value : " << multi[1][0][1] << std::endl;

    return 0;
}