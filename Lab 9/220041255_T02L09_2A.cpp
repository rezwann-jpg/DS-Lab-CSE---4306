#include <iostream>
#include <string>
#include <cctype>
#include <set>

struct Node {
    Node *child[26];
    bool endMark;
    int prefixCount;

    Node() : endMark(false), prefixCount(0) {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
private:
    Node *root;

    void Cleanup(Node *node) {
        if (!node)
            return;

        for (int i = 0; i < 26; i++) {
            Cleanup(node->child[i]);
        }

        delete node;
    }

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        Cleanup(root);
    }

    bool Search(const std::string& key) {
        Node *curr = root;

        for (char ch : key) {
            int idx = ch - 'a';
            if (curr->child[idx] == nullptr) {
                return false;
            }

            curr = curr->child[idx];
        }

        return curr->endMark;
    }

    void Insert(const std::string& key) {
        Node *curr = root;

        if (Search(key))
            return;

        for (char ch : key) {
            int idx = ch - 'a';
            if (curr->child[idx] == nullptr) {
                Node *newNode = new Node();
                curr->child[idx] = newNode;
            }

            curr = curr->child[idx];
            curr->prefixCount++;
        }

        curr->endMark = true;
    }

    int CountWords(const std::string& prefix) {
        Node *curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';
            if (curr->child[idx] == nullptr)
                return 0;

            curr = curr->child[idx];
        }

        return curr->prefixCount;
    }
};

int main() {
    int N, Q;
    std::string word, prefix;
    std::set<std::string> uniqueWords;

    std::cin >> N >> Q;
    Trie trie;

    for (int i = 0; i < N; i++) {
        std::cin >> word;
        for (char& ch : word)
            ch = std::tolower(ch);

        trie.Insert(word);
    }

    for (int i = 0; i < Q; i++) {
        std::cin >> prefix;
        for (char& ch : prefix)
            ch = std::tolower(ch);
        std::cout << trie.CountWords(prefix) << std::endl;
    }

    return 0;
}
