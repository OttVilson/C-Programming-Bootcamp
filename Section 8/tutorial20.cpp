#include <cstdlib>
#include <iostream>
#include <vector>

int Factorial(int N);
void PrintVectorHorizontally(std::vector<int> vector);
std::string InsertNumberIntoCell(int number, std::string cell);
std::string JoinColumns(std::vector<std::string> columns);
int Fibonacci(int index);

int main() {

    for (int i = 0; i < 10; i++) {
        std::cout << "The " << i << "th Fibonazzi number is " << Fibonacci(i) << ".\n";
    }

    std::vector<int> vector {1, 2, 14, 5, 8};
    PrintVectorHorizontally(vector);
    return 0;
}

int Factorial(int N) {
    if (N == 0) return 1;
    else return N * Factorial(N - 1);
}

void PrintVectorHorizontally(std::vector<int> vector) {
    int numberOfCells = vector.size();
    int cellLength = 4;
    int numberOfBorders = numberOfCells + 1;
    int lengthOfHorizontalLine = numberOfBorders + numberOfCells * cellLength;
    
    std::string horizontalLine (lengthOfHorizontalLine, '-');
    std::string cell (cellLength, ' ');

    std::vector<std::string> indices;
    std::vector<std::string> values;
    for (int i = 0; i < vector.size(); i++) {
        indices.push_back(InsertNumberIntoCell(i, cell));
        values.push_back(InsertNumberIntoCell(vector.at(i), cell));
    }

    std::vector<std::string> rows;
    rows.push_back(horizontalLine);
    rows.push_back(JoinColumns(indices));
    rows.push_back(horizontalLine);
    rows.push_back(JoinColumns(values));
    rows.push_back(horizontalLine);
    
    for (std::string row : rows)
        std::cout << row << "\n";
}

std::string InsertNumberIntoCell(int number, std::string cell) {
    std::string result (cell);
    std::string stringOfNumber = std::to_string(number);
    for (int i = 0; i < stringOfNumber.length(); i++) {
        result.replace(2 - i, 1, stringOfNumber.substr(stringOfNumber.length() - 1 - i, stringOfNumber.length() - i));
    }
    
    return result;
}

std::string JoinColumns(std::vector<std::string> columns) {
    std::string result = "|";
    for (std::string column : columns)
        result += column + "|";

    return result;
}

int Fibonacci(int index) {
    if (index == 0 || index == 1) return index;
    else return Fibonacci(index - 1) + Fibonacci(index - 2);
}