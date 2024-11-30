#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Solution {
private:
    class Node {
        public:
            std::vector<Node *> children;
            std::vector<std::string> suggestions;

            Node () : children(26, nullptr) {}
    };

    void Insert(const std::string& product) {
        Node *curr = root;

        for (char ch : product) {
            if (curr->children[ch - 'a'] == nullptr) {
                curr->children[ch - 'a'] = new Node();
            }
            curr = curr->children[ch - 'a'];

            if (curr->suggestions.size() < 3) {
                curr->suggestions.push_back(product);
            }
        }
    }

    Node *root;
public:
    Solution() {
        root = new Node();
    }

    void Solve(std::vector<std::string>& products, std::string searchWord) {
        std::sort(products.begin(), products.end());

        for (const std::string& product : products) {
            Insert(product);
        }

        std::vector<std::vector<std::string>> result;

        Node *curr = root;

        for (char ch : searchWord) {
            if (curr != nullptr) {
                curr = curr->children[ch - 'a'];
            }
            result.push_back(curr == nullptr ? std::vector<std::string>() : curr->suggestions);
        }

        for (const auto& row : result) {
            for (const auto& ans : row) {
                std::cout << ans << " ";
            }
            std::cout << std::endl;
        }
    }

};

int main () {
    Solution sol;

    std::vector<std::string> products;
    std::string input, token, searchWord;

    std::getline(std::cin, input);
    std::cin >> searchWord;

    std::stringstream ss(input);

    while (std::getline(ss, token, ' ')) {
        products.push_back(token);
    }

    sol.Solve(products, searchWord);

    return 0;
}