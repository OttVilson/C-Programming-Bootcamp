#include <cstdlib>
#include <iostream>
#include <deque>
#include <iterator>
#include <vector>

int main() {
    std::deque<int> deq {2, 4, 2, 1, 3};
    deq.push_front(12);
    deq.push_back(15);

    std::vector<int> vector {1, 3, 2, 5};
    std::vector<int>::iterator itr;

    for (itr = vector.begin(); itr < vector.end(); itr++) {
        std::cout << "Iterator : " << &itr << ", value : " << *itr << "\n";
    }

    std::vector<int>::iterator itr2 = vector.begin();
    advance(itr2, 1);
    std::cout << "With advance : " << *itr2 << "\n";
    
    auto itr3 = next(itr2, 2);
    std::cout << "With next : " << *itr3 << "\n";

    auto itr4 = prev(itr3, 2);
    std::cout << "With previous : " << *itr4 << "\n";

    std::vector<int> original {1, 2, 3, 4};
    std::vector<int> toInsert {5, 6};
    std::vector<int>::iterator itrForInsert = original.begin();
    advance(itrForInsert, 1);

    copy(toInsert.begin(), toInsert.end(), 
        inserter(original, itrForInsert));

    for (int element : original)
        std::cout << element << " ";

    std::cout << "\n";

    return 0;
}