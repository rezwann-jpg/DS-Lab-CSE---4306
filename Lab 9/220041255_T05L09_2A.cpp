#include <iostream>

struct Node {
    Node *child[26];
    bool endMark;
};

class Trie {
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

    bool Solve(std::string str) {
        int size = str.size();

        if (size == 0)
            return true;

        for (int i = 1; i <= size; i++) {
            if (Search(str.substr(0, i)) && Solve(str.substr(i, size - i))) {
                return true;
            }
        }

        return false;
    }

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

};

int main() {
    Trie trie;

    std::string input;
    while (std::cin >> input && input != "-1") {
        trie.Insert(input);
    }

    std::cin >> input;

    std::cout << (trie.Solve(input) ? "TRUE" : "FALSE") << std::endl;

    return 0;
}