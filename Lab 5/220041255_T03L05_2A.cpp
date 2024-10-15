#include <iostream>

struct Node {
    int data;
    Node *left, *right, *parent;
    
    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
    }
};

class BST {
private:
    Node* root;
    Node* findLCA(Node* node, int u, int v);

public:
    BST() : root(nullptr) {}

    void Insert(int value);
    int findLCA(int u, int v);
};

void BST::Insert(int value) {
    Node* newNode = new Node(value);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* current = root;
    Node* target = nullptr;

    while (current != nullptr) {
        target = current;
        if (newNode->data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = target;

    if (newNode->data < target->data)
        target->left = newNode;
    else
        target->right = newNode;
}

Node *BST::findLCA(Node *node, int u, int v) {
    if (!node)
        return nullptr;

    if (u < node->data && v < node->data) 
        return findLCA(node->left, u, v);

    if (u > node->data && v > node->data)
        return findLCA(node->right, u, v);

    return node;
}

int BST::findLCA(int u, int v) {
    Node *lca = findLCA(root, u, v);

    if (lca)
        return lca->data;

    return -1;
}

int main() {
    int N, num;
    std::cin >> N;

    BST tree;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        tree.Insert(num);
    }

    int q;
    std::cin >> q;

    while (q--) {
        int u, v;
        std::cin >> u >> v;

        std::cout << tree.findLCA(u, v) << std::endl;
    }

    return 0;
}