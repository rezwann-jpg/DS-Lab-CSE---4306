#include <iostream>
#include <sstream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, std::string> dictionary;
    std::string line;

    while (std::getline(std::cin, line) && !line.empty()) {
        std::istringstream iss(line);
        std::string englishWord, foreignWord;
        iss >> englishWord >> foreignWord;
        dictionary[foreignWord] = englishWord;
    }


    while (std::getline(std::cin, line) && !line.empty()) {
        if (dictionary.find(line) != dictionary.end()) {
            std::cout << dictionary[line] << std::endl;
        }
        else {
            std::cout << "eh" << std::endl;
        }
    }

    return 0;
}