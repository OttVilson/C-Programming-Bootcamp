#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    char str[] = {'A', ' ', 's', 't', 'r', 'i', 'n', 'g', '\0'};
    std::string str1 = "Tere";

    std::cout << str1[1] << " " << str1.at(2) << " " << str1.front() << " " << str1.back() << "\n";

    std::vector<std::string> strings;
    strings.push_back(str);
    strings.push_back(std::string(str));
    strings.push_back(std::string(2, 'K'));
    strings.push_back(str1.append("Tere taas", 2, 4));
    strings.push_back(std::string(str1, 2, 2));
    strings.push_back(str1.erase(2, 1));


    for (std::string element : strings)
        std::cout << element << "\n";

    if (str1.find("ere") != std::string::npos) {
        std::cout << str1.find("ere") << "\n";
    }

    std::cout << str1.substr(2, 2) << "\n"; 
    std::reverse(str1.begin(), str1.end());
    std::cout << str1 << "\n";

    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << str1 << "\n";
    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    std::cout << str1 << "\n";

    char aChar = 'z';
    int iChar = aChar;

    std::cout << iChar << "\n";
    std::cout << (int)'a' << "\n";
    std::string number = std::to_string(1 + 2);
    std::cout << number << 1 + 4 << std::endl;




    return 0;
}