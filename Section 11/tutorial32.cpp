#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

std::vector<std::string> StringToVector(std::string& sentence, char separator = ' '); 

int main() {
    std::ofstream writeToFile;
    std::ifstream readFromFile;

    std::string txtToWrite;
    std::string txtToRead;

    // writeToFile.open("test.txt", std::ios_base::out | std::ios_base::app);
    // if (writeToFile.is_open()) {
    //     writeToFile << "Tere tulemast\n";
    //     std::cout << "Enter line to append to file : ";
    //     getline(std::cin, txtToWrite);
    //     writeToFile << txtToWrite << "\n";
    // }
    // writeToFile.close();

    std::vector<std::string> allWords;
    std::vector<std::string> wordsOnLine;

    readFromFile.open("test.txt");
    if (readFromFile.is_open()) {
        int i = 0;
        while (readFromFile.good()) {
            i++;
            getline(readFromFile, txtToRead);
            wordsOnLine = StringToVector(txtToRead);
            std::cout << "The number of words on line " << i << " is " << wordsOnLine.size() << "\n";
            for (std::string word : wordsOnLine)
                allWords.push_back(word);
        }

        int sum = 0;
        for (std::string word : allWords)
            sum += word.length();

        std::cout << "The average length of a word is " << sum / allWords.size() << "\n";

    }
    readFromFile.close();


    return 0;
}

std::vector<std::string> StringToVector(std::string& sentence, char separator) {
    std::vector<std::string> result;
    std::stringstream ss (sentence);
    std::string stringCut;

    while (getline(ss, stringCut, separator))
        result.push_back(stringCut);

    return result;
}
