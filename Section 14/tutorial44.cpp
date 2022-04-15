#include <cstdlib>
#include <iostream>
#include <forward_list>

template<typename T>
void Print(const std::forward_list<T>& list) {
    for (T element : list)
        std::cout << element << " ";
    
    std::cout << "\n";
}


int main() {

    std::forward_list<int> list;
    list.push_front(4);
    list.push_front(3);
    Print(list);

    std::cout << list.front() << "\n";
    std::forward_list<int>::iterator it = list.begin();

    int arr[2] = {5, 7};
    it = list.insert_after(it, arr, arr + 2);
    Print(list);

    std::cout << *it << "\n";

    list.erase_after(list.begin(), next(list.begin(), 3));
    Print(list);
    std::cout << *it << "\n";

    list.insert_after(it, 11);
    Print(list);
    std::cout << *next(it, 1) << "\n";

    return 0;
}