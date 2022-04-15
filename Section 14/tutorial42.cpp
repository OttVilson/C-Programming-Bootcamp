#include <cstdlib>
#include <iostream>
#include <deque>
// #include <list>
// #include <forward_list>

bool IsEven(const int& number) {
    return number % 2 == 0;
}

template<typename T>
void Print(const std::deque<T>& deque) {
    printf("Printing deque of size %d.\n", deque.size());
    for (int i = 0; i < deque.size(); i++)
        std::cout << deque.at(i) << " ";

    std::cout << "\n";
}

int main() {
    std::deque<int> deq1;
    Print(deq1);

    deq1.emplace_back(2);
    Print(deq1);
    deq1.pop_front();

    deq1.emplace_front(3);
    Print(deq1);
    deq1.pop_back();

    deq1.emplace_back(2);
    deq1.emplace_back(3);
    deq1.emplace_front(4);
    deq1.assign({5, 6, 7});
    Print(deq1);

    std::deque<int>::iterator it = deq1.begin() + 1;
    int tempArray[2] = {3, 8};
    deq1.insert(it, tempArray, tempArray + 2);
    deq1.erase(deq1.begin() + 4, deq1.end() - 3);
    Print(deq1);

    return 0;
}