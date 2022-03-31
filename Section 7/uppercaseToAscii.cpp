#include <cstdlib>
#include <iostream>
#include <algorithm>

void toAsciiLowerCase(int* uppercaseAscii, int length);

int main() {
    std::string input;
    std::cout << "Enter a word : ";
    std::cin >> input;

    // transform(input.begin(), input.end(), input.begin(), ::toupper);
    // std::cout << "Uppercase version : " << input << "\n";

    int asciiValues[input.length()];
    for (int i = 0; i < input.length(); i++) {
        asciiValues[i] = input[i];
    }

    for (int asciiValue : asciiValues)
        std::cout << asciiValue;

    std::cout << std::endl;
 
    // toAsciiLowerCase(asciiValues, input.length());

    char characters[input.length() + 1];
    for (int i = 0; i < input.length(); i++) {
        characters[i] = asciiValues[i];
    }
    characters[input.length()] = '\0';
    std::cout << characters << std::endl;

    return 0;
}

void toAsciiLowerCase(int* uppercaseAscii, int length) {
    for (int i = 0; i < length; i++) {
        *uppercaseAscii += 32;
        uppercaseAscii++;
    }
}