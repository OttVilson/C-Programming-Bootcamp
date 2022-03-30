#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::vector<int> vecRandNums(2);
    vecRandNums[0] = 10;
    vecRandNums[1] = 20;

    std::cout << vecRandNums[1] << "\n";

    vecRandNums.push_back(30);

    std::cout << "Size : " << vecRandNums.size() << "\n";

    std::cout << vecRandNums[0] << " " << vecRandNums[1] << " " << vecRandNums[2] << "\n";

    std::vector<int>::iterator it;
    it = find(vecRandNums.begin(), vecRandNums.end(), 20);

    std::cout << *it << std::endl;


    std::string sentence = "This is a random string";
    std::vector<std::string> words;
    std::stringstream ss(sentence);

    std::string individualString;
    char space = ' ';

    while (getline(ss, individualString, space)) {
        words.push_back(individualString);
    }

    for (int i = 0; i < words.size(); i++)
        std::cout << words[i] << "\n";

    return 0;
}