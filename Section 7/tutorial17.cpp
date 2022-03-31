#include <cstdlib>
#include <iostream>
#include <sstream>

std::string CaesarCipher(std::string message, int shift, bool encrypt);
char Shift(char character, int shift, bool encrypt);

void SolveForX(std::string linearEquation);

int main() {
    SolveForX("a / 12 = 6");

    std::stringstream ss ("   ha ha haa   ");
    std::string temp;
    while (getline(ss, temp, ' ')) {
        if (temp.empty()) temp = "EMPTY";
        std::cout << temp << "\n";
    }

    std::string message = "Make Me A Secret!";
    std::string secret = CaesarCipher(message, 5, true);

    std::cout << message << "\n";
    std::cout << secret << "\n";
    std::cout << CaesarCipher(secret, 5, false) << "\n";

    return 0;
}

std::string CaesarCipher(std::string message, int shift, bool encrypt) {
    for (char& character : message) {
        if (isalpha(character))
            character = Shift(character, shift, encrypt);      
    }

    return message;
}

char Shift(char character, int shift, bool encrypt) {
    int base = isupper(character) ? 'A' : 'a';
    int range = 'Z' - 'A' + 1; 

    int sign = encrypt ? -1 : +1;

    int temp = character - base + range;
    temp = (temp + sign * shift) % range + base;

    return (char) temp;
}

void SolveForX(std::string linearEquation) {
    int positionOfEqualsSign = linearEquation.find(" = ");
    std::string lhs = linearEquation.substr(0, positionOfEqualsSign);
    std::string rhs = linearEquation.substr(positionOfEqualsSign + 3);
    char operation;
    char variable;
    int primary;
    int secondary;
    int answer;

    std::stringstream lhsStream (lhs);
    std::string current;
    while(getline(lhsStream, current, ' ')) {
        if (current.length() == 1) {
            char c = current.at(0);
            if (isdigit(c)) secondary = c - '0';
            else if (isalpha(c)) variable = c;
            else operation = c;
        } else {
            secondary = stoi(current);
        }
    }
    primary = stoi(rhs);

    if (operation == '*') answer = primary / secondary;
    if (operation == '/') answer = primary * secondary;
    if (operation == '+') answer = primary - secondary;
    if (operation == '-') answer = primary + secondary;

    std::cout << "The variable " << variable << " has value " << answer << "\n";
}