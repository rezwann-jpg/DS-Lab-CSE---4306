#include <iostream>
#include <string>
#include <sstream>

struct Node {
    Node *child[26];
    bool endMark;

    Node() : endMark(false) {
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

    void Insert(const std::string& key) {
        Node *curr = root;

        for (char ch : key) {
            int idx = ch - 'a';
            if (curr->child[idx] == nullptr) {
                Node *newNode = new Node();
                curr->child[idx] = newNode;
            }

            curr = curr->child[idx];
        }

        curr->endMark = true;
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

    void Display(Node *node, char str[], int level) {
        if (!node)
            return;

        if (node->endMark) {
            str[level] = '\0';
            std::cout << str << " ";
        }

        for (int i = 0; i < 26; i++) {
            str[level] = i + 'a';
            Display(node->child[i], str, level + 1);
        }
    }

    void Display() {
        char str[20];
        int level = 0;

        Display(root, str, level);
    }
};

int main() {
    Trie trie;
    std::string input, word;

    std::getline(std::cin, input);

    std::istringstream ss(input);

    while (ss >> word) {
        trie.Insert(word);
    }

    trie.Display();
    std::cout << std::endl;

    std::getline(std::cin, input);

    std::istringstream ss2(input);

    while (ss2 >> word) {
        std::cout << (trie.Search(word) ? "T" : "F") << " ";
    }
    std::cout << std::endl;

    return 0;
}
