#include <iostream>
#include <vector>
#include <string>

struct Node {
    char data;
    Node *left;
    Node *right;

    Node (char value) : data(value), left(nullptr), right(nullptr) { }
};

Node *buildTree(std::vector<char>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == '-') {
        index++;
        return nullptr;
    }

    Node *root = new Node(preorder[index++]);

    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}

void inorderTraversal(Node *root) {
    if (!root) {
        std::cout << " - ";
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if (!root) {
        std::cout << " - ";
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    std::string input;
    std::vector<char> preorder;

    std::getline(std::cin, input);

    for (char ch : input) {
        if (ch == ' ') {
            continue;
        }

        preorder.push_back(ch);
    }

    int index = 0;

    Node *root = buildTree(preorder, index);

    std::cout << "Inorder: \n";
    inorderTraversal(root);
    std::cout << std::endl;
    
    std::cout << "Postorder: \n";
    postorderTraversal(root);
    std::cout << std::endl;

    return 0;
}