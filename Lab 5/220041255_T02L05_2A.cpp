#include <iostream>
#include <queue>

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

    void inorderTraversal(Node* node);
    void preorderTraversal(Node* node);
    void postorderTraversal(Node* node);
    void levelOrderTraversal(Node* node);

public:
    BST() : root(nullptr) {}

    void Insert(int value);
    void Inorder();
    void Preorder();
    void Postorder();
    void Level_order();
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

void BST::inorderTraversal(Node* node) {
    if (!node) return;

    inorderTraversal(node->left);
    std::cout << node->data << "(";
    if (node->parent)
        std::cout << node->parent->data;
    else
        std::cout << "null";
    std::cout << ") ";
    inorderTraversal(node->right);
}

void BST::Inorder() {
    if (!root) {
        std::cout << "Tree is empty.\n";
        return;
    }
    std::cout << "Inorder: ";
    inorderTraversal(root);
    std::cout << std::endl;
}

void BST::preorderTraversal(Node* node) {
    if (!node) return;

    std::cout << node->data << "(";
    if (node->parent)
        std::cout << node->parent->data;
    else
        std::cout << "null";
    std::cout << ") ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void BST::Preorder() {
    if (!root) {
        std::cout << "Tree is empty.\n";
        return;
    }
    std::cout << "Preorder: ";
    preorderTraversal(root);
    std::cout << std::endl;
}

void BST::postorderTraversal(Node* node) {
    if (!node) return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << "(";
    if (node->parent)
        std::cout << node->parent->data;
    else
        std::cout << "null";
    std::cout << ") ";
}

void BST::Postorder() {
    if (!root) {
        std::cout << "Tree is empty.\n";
        return;
    }
    std::cout << "Postorder: ";
    postorderTraversal(root);
    std::cout << std::endl;
}

void BST::levelOrderTraversal(Node* node) {
    if (!node) return;

    std::queue<Node*> q;
    q.push(node);

    int level = 1;
    while (!q.empty()) {
        int levelSize = q.size();
        std::cout << "Level " << level << ": ";

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            std::cout << current->data << "(";
            if (current->parent)
                std::cout << current->parent->data;
            else
                std::cout << "null";
            std::cout << ") ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        std::cout << std::endl;
        level++;
    }
}

void BST::Level_order() {
    if (!root) {
        std::cout << "Tree is empty.\n";
        return;
    }
    levelOrderTraversal(root);
}

int main() {
    BST tree;

    int N, num;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        tree.Insert(num);
    }

    int choice;
    while (true) {
        std::cin >> choice;
        switch (choice) {
        case 1:
            tree.Inorder();
            break;
        case 2:
            tree.Preorder();
            break;
        case 3:
            tree.Postorder();
            break;
        case 4:
            tree.Level_order();
            break;
        case 5:
            exit(0);
        }
    }

    return 0;
}