#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>

typedef long long int i64;

const int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

i64 hash_function(const std::string& word) {
    std::unordered_set<char> uniqueChars;
    for (char ch : word) {
        uniqueChars.insert(ch);
    }

    i64 hash = 1;
    std::unordered_set<char>::iterator it;
    for (it = uniqueChars.begin(); it != uniqueChars.end(); it++) {
        hash *= primes[*it - 'a'];
    }

    return hash;
}

int main() {
    std::string input, word;
    std::getline(std::cin, input);
    std::getline(std::cin, word);

    i64 targetHash = hash_function(word);

    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        if (hash_function(token) == targetHash) {
            std::cout << token << " ";
        }
    }

    return 0;
}