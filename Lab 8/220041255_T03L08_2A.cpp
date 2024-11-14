#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cctype>
#include <utility>

std::string cleanWord(const std::string& word) {
    std::string result;
    for (int i = 0; i < word.size(); i++) {
        if (std::isalpha(word[i])) {
            result += std::tolower(word[i]);
        }
    }

    return result;
}

void Solve(const std::string& sentence) {
    std::istringstream stream(sentence);
    std::unordered_map<std::string, int> wordCount;
    std::string word;

    while (stream >> word) {
        std::string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty()) {
            wordCount[cleanedWord]++;
        }
    }

    std::vector<std::pair<std::string, int>> duplicateWord;
    for (auto it = wordCount.begin(); it != wordCount.end(); it++) {
        if (it->second > 1) {
            duplicateWord.push_back(std::make_pair(it->first, it->second));
        }
    }

    for (int i = 0; i < duplicateWord.size(); i++) {
        std::cout << duplicateWord[i].first << " " << duplicateWord[i].second << std::endl;
    }
}

int main() {
    std::string sentence = "I know you know this but you do not know of unknown trolls because no known trolls will sew by windows though they will owe you a hello when they throw a hoe as it will go low and blow a hole in that window and so it will follow that it happened awhile ago as a troll will stand on a knoll and show you how to throw snow tomorrow at a rhino named Joe who plays piano as he sips a cappucino and sings soprano in an inferno caused by a volcano in Reno with a casino at the bottom. Of the volcano";
    ///std::getline(std::cin, sentence);

    Solve(sentence);

    return 0;
}

/*
I know you know this, but you do not know of unknown trolls, because no known trolls will sew by windows, though they will owe you a hello when they throw a hoe, as it will go low and blow a hole in that window and so it will follow, that it happened awhile ago, as a troll will stand on a knoll and show you how to throw snow tomorrow at a rhino named Joe, who plays piano as he sips a cappucino and sings soprano in an inferno caused by a volcano in Reno with a casino at the bottom. Of the volcano.

I know you know this but you do not know of unknown trolls because no known trolls will sew by windows though they will owe you a hello when they throw a hoe as it will go low and blow a hole in that window and so it will follow that it happened awhile ago as a troll will stand on a knoll and show you how to throw snow tomorrow at a rhino named Joe who plays piano as he sips a cappucino and sings soprano in an inferno caused by a volcano in Reno with a casino at the bottom. Of the volcano

This refers to an exam where James had written ‘had had’ where John had written just ‘ had’. The examiner had approved James’ version.

This refers to an exam where James had written had had where John had written just had The examiner had approved James version
*/
