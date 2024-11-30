#include <iostream>
#include <vector>
#include <string>

struct Node {
    Node () : links(58, nullptr), endMark(false) {}

    bool containsKey(char ch) {
        return (links[ch - 'A'] != nullptr);
    }

    void put(char ch, Node *node) {
        links[ch - 'A'] = node;
    }

    Node *get(char ch) {
        return links[ch - 'A'];
    }

    void setEnd() {
        endMark = true;
    }

    bool isEnd() {
        return endMark;
    }

private:
    std::vector<Node *> links;
    bool endMark;

};

class Trie {
private:
    Node *root;

public:
    Trie () {
        root = new Node();
    }

    void Insert(const std::string& key) {
        Node *curr = root;
        for (const char ch : key) {
            if (!curr->containsKey(ch)) {
                curr->put(ch, new Node());
            }
            curr = curr->get(ch);
        }
        curr->setEnd();
    }

    bool Search(const std::string& key) {
        Node *curr = root;

        for (char ch : key) {
            if (curr->containsKey(ch)) {
                curr = curr->get(ch);
            }
            else if (islower(ch)) {
                continue;
            }
            else {
                return false;
            }
        }

        return curr->isEnd();
    }

};

class Solution {
public:
    void Solve(std::vector<std::string>& words, std::string abbreviation) {
        Trie trie;
        trie.Insert(abbreviation);
        std::vector<bool> ans;
        for (auto word : words) {
            ans.push_back(trie.Search(word));
        }

        for (auto it : ans) {
            std::cout << (it ? "T" : "F") << " ";
        }
        std::cout << std::endl;
    }

};

int main() {
    Solution sol;

    std::vector<std::string> words;
    std::string input;

    while (std::cin >> input && input != "-1") {
        words.push_back(input);
    }

    std::cin.ignore();
    std::cin >> input;

    sol.Solve(words, input);

    return 0;
}