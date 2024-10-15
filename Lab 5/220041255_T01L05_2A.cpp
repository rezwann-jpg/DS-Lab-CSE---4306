#include <iostream>
#include <cstdlib>

struct Node {
    int data;
    Node *left, *right, *parent;
    int height;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        height = 0;
    }
};

class BST {
private:
    Node* root;

    void inorderTraversal(Node *node);
    void updateHeight(Node* node);
    Node* findMin(Node *node);
    Node* findMax(Node *node);
    Node* findInorderSuccessor(Node *node);
    Node* findInorderPredecessor(Node *node);

public:
    BST() : root(nullptr) {}

    void Insert(int value);
    void Print_tree();
    Node* Search(int value);
    int getHeight(Node *node);
    void Before_after(int value);
};

void BST::updateHeight(Node *node) {
    if (node) {
        int leftHeight = node->left ? node->left->height : -1;
        int rightHeight = node->right ? node->right->height : -1;
        node->height = std::max(leftHeight, rightHeight) + 1;
    }
}

void BST::Insert(int value) {
    Node *newNode = new Node(value);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node *current = root;
    Node *target = nullptr;

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

    current = newNode->parent;
    while (current) {
        updateHeight(current);
        current = current->parent;
    }
}

void BST::Print_tree() {
    if (root == nullptr) {
        std::cout << "Tree is empty.";
        return;
    }
    inorderTraversal(root);
    std::cout << std::endl;
}

void BST::inorderTraversal(Node *node) {
    if (!node)
        return;

    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

Node *BST::Search(int value) {
    Node *current = root;

    while (current) {
        if (current->data == value)
            return current;
        else if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return nullptr;
}

int BST::getHeight(Node *node) {
    if (!node)
        return -1;

    return node->height;
}

Node *BST::findMin(Node *node) {
    while (node && node->left)
        node = node->left;
    return node;
}

Node *BST::findMax(Node *node) {
    while (node && node->right)
        node = node->right;
    return node;
}

Node *BST::findInorderSuccessor(Node *node) {
    if (!node)
        return nullptr;

    if (node->right)
        return findMin(node->right);

    Node *parent = node->parent;
    while (parent && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node *BST::findInorderPredecessor(Node *node) {
    if (!node)
        return nullptr;

    if (node->left)
        return findMax(node->left);

    Node *parent = node->parent;
    while (parent && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void BST::Before_after(int value) {
    Node *node = Search(value);
    if (!node) {
        std::cout << "Not Found\n";
        return;
    }

    Node *pred = findInorderPredecessor(node);
    Node *succ = findInorderSuccessor(node);

    if (pred)
        std::cout << pred->data << " ";
    else
        std::cout << "null ";

    if (succ)
        std::cout << succ->data;
    else
        std::cout << "null";

    std::cout << std::endl;
}

int main() {
    BST tree;

    int N, num;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        tree.Insert(num);
    }

    tree.Print_tree();

    while (true) {
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 3: {
            int x;
            std::cin >> x;
            Node *found = tree.Search(x);
            if (found) {
                std::cout << "Present\n";
                std::cout << "Parent(";
                if (found->parent)
                    std::cout << found->parent->data << "), ";
                else
                    std::cout << "Null), ";
                std::cout << "Left(";
                if (found->left)
                    std::cout << found->left->data << "), ";
                else
                    std::cout << "Null), ";
                std::cout << "Right(";
                if (found->right)
                    std::cout << found->right->data << ")\n";
                else
                    std::cout << "Null)\n";
            } else
                std::cout << "Not Present\n";
            break;
        }
        case 4: {
            int x;
            std::cin >> x;
            Node *toFind = tree.Search(x);
            std::cout << tree.getHeight(toFind) << std::endl;
            break;
        }
        case 5: {
            int x;
            std::cin >> x;
            tree.Before_after(x);
            break;
        }
        case 6:
            exit(0);
        }
    }

    return 0;
}