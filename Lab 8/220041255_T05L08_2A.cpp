#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

void Solve(const std::vector<std::string>& words) {
    std::vector<std::string> hash = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    std::unordered_set<std::string> unique;

    for (int i = 0; i < words.size(); i++) {
        std::string temp = "";
        for (int j = 0; j < words[i].length(); j++) {
            temp += hash[words[i][j] - 'a'];
        }
        unique.insert(temp);
    }

    std::cout << unique.size() << std::endl;
    
    std::unordered_set<std::string>::iterator it;

    for (it = unique.begin(); it != unique.end(); it++) {
        std::cout << *it << std::endl;
    }
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> words(N);

    for (int i = 0; i < N; i++) {
        std::cin >> words[i];
    }

    Solve(words);

    return 0;
}