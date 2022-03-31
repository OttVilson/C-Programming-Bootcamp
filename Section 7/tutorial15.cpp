#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> StringToVector(std::string input, char separator = ' ');
std::string VectorToString(std::vector<std::string> words, char separator = ' ');
std::string Trim(std::string word);

int main() {
    std::string input;
    std::cout << "Enter a string : ";
    getline(std::cin, input);

    std::vector<std::string> words = StringToVector(input);

    for (std::string word : words)
        std::cout << word << "\n";

    std::string output = VectorToString(words);
    std::cout << output << std::endl;

    std::cout << "Enter something with leading and trailing spaces : ";
    getline(std::cin, input);
    std::cout << "The length of the input '" << input << "' is " << input.length() << ".\n";
    std::cout << "After trimming the word is '" << Trim(input) << "' with length " << Trim(input).length() << ".\n";

    return 0;
}

std::vector<std::string> StringToVector(std::string input, char separator) {
    std::stringstream ss(input);
    std::string word;
    std::vector<std::string> words;
    while (getline(ss, word, separator))
        words.push_back(word);

    return words;
}

std::string VectorToString(std::vector<std::string> words, char separator) {
    std::string sentence = words.at(0);
    std::string separatorString = std::string(1, separator);
    for (int i = 1; i < words.size(); i++)
        sentence.append(separatorString).append(words.at(i));

    return sentence;
}

std::string Trim(std::string word) {
    std::string whitespaces = " \t\f\n\r";
    int start = word.find_first_not_of(whitespaces);
    int endExclusive = word.find_last_not_of(whitespaces) + 1;
    return word.substr(start, endExclusive - start);
}