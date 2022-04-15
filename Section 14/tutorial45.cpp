#include <cstdlib>
#include <iostream>
#include <set>

template<typename T>
void Print(const std::set<T>& set) {

    for (T element : set)
        std::cout << element << " ";

    std::cout << "\n";
}

int main() {
    std::set<int> set;
    int arr[9] = {4, 2, 3, 5, 5, 7, 1, 8, 11};

    set.insert(arr, arr + 9);
    Print(set);

    auto low = set.lower_bound(6);
    std::cout << *low << "\n";

    auto upper = set.upper_bound(6);
    std::cout << *upper << "\n";

    ++upper;
    std::cout << *upper << "\n";

    set.erase(3);
    Print(set);
    

    std::set<int>::iterator it = set.end();
    advance(it, -2);
    set.erase(it, set.end());
    Print(set);

    std::multiset<int> mset {2, 4, 4, 4, 3, 1, 8};
    for (int i : mset)
        std::cout << i << " ";

    std::cout << "\n";

    return 0;
}