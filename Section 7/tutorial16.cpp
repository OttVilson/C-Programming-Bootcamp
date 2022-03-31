#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> FindSubstringMatches(std::string fullString, std::string subString);
std::string ReplaceAllSubstrings(std::string fullString, std::string subString, std::string replaceWith);

int main() {
    std::string fullString = "Tere tuleremast sierea.";
    std::string subString = "ere";

    std::vector<int> indices = FindSubstringMatches(fullString, subString);
    
    for (int index : indices)
        std::cout << index << "\n";
    std::cout << fullString << "\n";
    std::cout << ReplaceAllSubstrings(fullString, subString, "----") << std::endl;

    char letterZ = 'Z';
    char num3 = '3';
    char aSpace = ' ';

    std::cout << "Is z a number or letter " << isalnum(letterZ) << "\n";
    std::cout << "Is z a number " << isalpha(letterZ) << "\n";
    std::cout << "Is 3 a letter " << isalpha(num3) << "\n";
    std::cout << "Is z an uppercase letter " << isupper(letterZ) << "\n";
    std::cout << "is . a punctuation " << ispunct('.') << "\n";
    std::cout << "is ' ' a space " << isspace(aSpace) << "\n";
    std::cout << "is . a space " << isspace('.') << "\n";


    return 0;
}

std::vector<int> FindSubstringMatches(std::string fullString, std::string subString) {
    std::vector<int> indices;
    int index, position = 0;
    while (true) {
        index = fullString.find(subString, position);
        if (index == std::string::npos) break;

        indices.push_back(index);
        position = index + subString.length();
    }

    return indices;
}

std::string ReplaceAllSubstrings(std::string fullString, std::string subString, std::string replaceWith) {
    std::vector<int> indices = FindSubstringMatches(fullString, subString);
    reverse(indices.begin(), indices.end());
    int numberOfCharatersToReplace = subString.length();
    std::string result (fullString);

    for (int index : indices)
        result.replace(index, numberOfCharatersToReplace, replaceWith);

    return result;
}
