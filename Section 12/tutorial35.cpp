#include <cstdlib>
#include <iostream>
#include <vector>
#include <functional>

template <typename T>
void Times2(T t) {
    std::cout << t << " * 2 = " << t * 2 << "\n";
} 

void Times3(int number) {
    std::cout << number << " * 2 = " << number * 2 << "\n";
}

template <typename T>
std::vector<T> Filter(std::vector<T> vector, std::function<bool(T)> Predicate) {
    std::vector<T> result;
    for (T t : vector)
        if (Predicate(t))
            result.push_back(t);

    return result;
}

bool IsEven(int number) {
    return number % 2 == 0;
}

bool LengthIs5(std::string word) {
    return word.length() == 5;
}

template <typename T, typename U>
class Pair {
    public:
        T first;
        U second;
        static int numberOfPairs;
        Pair(T t, U u) {
            first = t, second = u;
            ++numberOfPairs;
        }
        void Print() {
            std::cout << "First (T) is " << first << ", and second (U) is " << second << "\n";
        }
};

template<typename T, typename U> int Pair<T, U>::numberOfPairs;

template<typename T>
T Max(std::vector<T> input) {
    T max = input[0];
    for (T entry : input)
        if (entry > max)
            max = entry;

    return max; 
}

template <typename T>
T Max(T first, T second) {
    return first > second ? first : second;
}

int main() {
    std::string input = "Tere";
    Pair<std::string, int> pair (input, 3);
    pair.Print();
    Pair<std::string, int> pair3 (input, 5);
    pair3.Print();
    std::cout << pair.numberOfPairs << "\n";
    
    Pair<double, int> pair2 (2.5, 3);
    pair2.Print();
    std::cout << pair2.numberOfPairs << "\n";

    std::vector<int> numbers {1, 7, 2, 3, 1, 5, 8, 15, 11, 12};
    for (int number : Filter<int>(numbers, IsEven))
        std::cout << number << "\n";

    std::cout << "\n";

    std::vector<std::string> words {"Tere", "Tulemast", "yehuu", "Viisi", "Kuula", "ah", "Eh"};
    for (std::string word : Filter<std::string>(words, LengthIs5))
        std::cout << word << "\n";

    std::cout << "Max is " << Max(numbers) << "\n";
    std::cout << "Max is " << Max(words) << "\n";

    std::cout << "Max 4 or 8 = " << Max(4, 8) << "\n";    
    std::cout << "Max A or B = " << Max('A', 'B') << "\n";    
    std::cout << "Max Dog or Cat = " << Max("Dog", "Cat") << "\n";    

    return 0;
}
