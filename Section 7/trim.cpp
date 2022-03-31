#include <cstdlib>
#include <iostream>

int main() {

    std::string input;
    std::cout << "Enter a word with trailing whitespaces : ";
    getline(std::cin, input);

    std::cout << "The length of the word is " << input.length() << std::endl;

    int start = input.find_first_not_of(' ');
    int exclusiveEnd = input.find_last_not_of(' ') + 1;

    std::string trimmed = input.substr(start, exclusiveEnd - start);
    std::cout << "The trimmed version " << trimmed << " has length " << trimmed.length() << std::endl;

    return 0;
}