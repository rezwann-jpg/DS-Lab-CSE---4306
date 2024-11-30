#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::vector<Node *> children;

    Node () : children(10, nullptr) { }
};

class Solution {
private:
    class Tire {
    private:
        Node *root;

    public:
        Tire() {
            root = new Node();
        }

        void Insert(const std::string& num) {
            Node *curr = root;
            for (const char ch : num) {
                const int idx = ch - '0';
                if (curr->children[idx] == nullptr)
                    curr->children[idx] = new Node();
                curr = curr->children[idx];
            }
        }

        int Search(const std::string& num) {
            int prefixLength = 0;
            Node *curr = root;
            for (const char ch : num) {
                const int idx = ch - '0';
                if (curr->children[idx] == nullptr)
                    break;
                curr = curr->children[idx];
                prefixLength++;
            }

            return prefixLength;
        }
    };

public:
    void Solve(std::vector<int>& arr1, std::vector<int>& arr2) {
        int ans = 0;
        Tire trie;

        for (const int num : arr1) {
            trie.Insert(std::to_string(num));
        }

        for (const int num : arr2) {
            ans = std::max(ans, trie.Search(std::to_string(num)));
        }

        std::cout << ans << std::endl;
    }
};

int main() {
    Solution sol;
    int l1, l2;

    std::cin >> l1 >> l2;

    std::vector<int> arr1(l1), arr2(l2);

    for (int i = 0; i < l1; i++) {
        std::cin >> arr1[i];
    }

    for (int i = 0; i < l2; i++) {
        std::cin >> arr2[i];
    }

    sol.Solve(arr1, arr2);

    return 0;
}