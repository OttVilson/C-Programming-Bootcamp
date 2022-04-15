#include <cstdlib>
#include <iostream>
#include <list>
#include <iterator>

template<typename T>
void Print(std::list<T>& list) {
    auto it = list.begin();
    for (int i = 0; i < list.size(); i++) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
}

bool IsEven(const int& number) {
    return number % 2 == 0;
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    std::list<int> list;
    list.insert(list.begin(), array, array + 5);

    Print(list);

    std::list<int> list2;
    list2.insert(list2.begin(), list.begin(), list.end());
    Print(list2);

    auto it2 = list2.begin();
    int arr2[6] = {8, 9, 7, 7, 7, 7};

    list2.insert(next(it2, 2), arr2, arr2 + 6);
    Print(list2);
    list2.sort();
    Print(list2);
    list2.sort([](const int& n, const int& m) { return n > m; });
    Print(list2);
    list2.reverse();
    Print(list2);
    list2.unique();
    Print(list2);
    list2.remove(5);
    Print(list2);
    list2.remove_if(IsEven);
    Print(list2);
    list2.merge(list);
    Print(list2);



    return 0;
}