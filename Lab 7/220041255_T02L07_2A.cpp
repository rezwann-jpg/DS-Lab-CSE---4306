#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}
    void insertion(int key) {
        root = insert(root, key);
    }

    Node* insert(Node* node, int key) {
        Node* newNode = new Node(key);

        if (node == nullptr) return newNode;

        Node* parent = nullptr;
        Node* current = node;
        while (current != nullptr) {
            parent = current;
            if (key < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (key < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        newNode->parent = parent;

        updateHeight(newNode);

        checkBalance(newNode);

        return node;
    }
    void updateHeight(Node* node) {
        while (node != nullptr) {
            node->height = 1 + max(height(node->left), height(node->right));
            node = node->parent;
        }
    }
    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr) {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;

        updateHeight(x);
        updateHeight(y);
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right != nullptr) {
            y->right->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;

        updateHeight(x);
        updateHeight(y);
    }

    void checkBalance(Node* node) {
        Node* current = node;
        while (current != nullptr) {
            int balance = balanceFactor(current);

            if (balance > 1 && balanceFactor(current->left) >= 0) {
                cout << "Imbalance at node: " << current->data << endl;
                cout << "LL case" << endl;
                rightRotate(current);
            } else if (balance < -1 && balanceFactor(current->right) <= 0) {
                cout << "Imbalance at node: " << current->data << endl;
                cout << "RR case" << endl;
                leftRotate(current);
            } else if (balance > 1 && balanceFactor(current->left) < 0) {
                cout << "Imbalance at node: " << current->data << endl;
                cout << "LR case" << endl;
                leftRotate(current->left);
                rightRotate(current);
            } else if (balance < -1 && balanceFactor(current->right) > 0) {
                cout << "Imbalance at node: " << current->data << endl;
                cout << "RL case" << endl;
                rightRotate(current->right);
                leftRotate(current);
            } /* else {
                cout << "Balanced" << endl;
            } */

            updateHeight(current);
            current = current->parent;
        }
    }

    void printAVL(Node* node) {
        if (node == nullptr) return;

        inOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << "(" << balanceFactor(node) << ") ";
        inOrderTraversal(node->right);
    }
};

int main() {
    AVLTree tree;

    int value;
    while (cin >> value && value != -1) {
        tree.insertion(value);
        tree.printAVL(tree.root);
        cout << endl;
    }

    return 0;
}

