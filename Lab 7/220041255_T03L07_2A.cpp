#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    int size;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), height(1), size(1) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    void insertion(int key) {
        root = insert(root, key);
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);

        Node* parent = nullptr;
        Node* current = node;
        Node* newNode = new Node(key);
        
        while (current != nullptr) {
            parent = current;
            current->size++;
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

        return root;
    }

    int lowerCount(int query) {
        Node* current = root;
        int count = 0;

        while (current != nullptr) {
            if (query <= current->data) {
                current = current->left;
            } else {
                count += (current->left ? current->left->size : 0) + 1;
                current = current->right;
            }
        }
        return count;
    }

    void updateHeight(Node* node) {
        while (node != nullptr) {
            node->height = 1 + max(height(node->left), height(node->right));
            node->size = 1 + (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0);
            node = node->parent;
        }
    }

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left) y->left->parent = x;

        y->parent = x->parent;

        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->left = x;
        x->parent = y;

        updateHeight(x);
        updateHeight(y);
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right) y->right->parent = x;

        y->parent = x->parent;

        if (!x->parent) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;

        y->right = x;
        x->parent = y;

        updateHeight(x);
        updateHeight(y);
    }

    void checkBalance(Node* node) {
        while (node != nullptr) {
            int balance = balanceFactor(node);

            if (balance > 1 && balanceFactor(node->left) >= 0) {
                rightRotate(node);
            } else if (balance < -1 && balanceFactor(node->right) <= 0) {
                leftRotate(node);
            } else if (balance > 1 && balanceFactor(node->left) < 0) {
                leftRotate(node->left);
                rightRotate(node);
            } else if (balance < -1 && balanceFactor(node->right) > 0) {
                rightRotate(node->right);
                leftRotate(node);
            }

            node->size = 1 + (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0);
            updateHeight(node);
            node = node->parent;
        }
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << "(" << node->size << ") ";
        inOrderTraversal(node->right);
    }

    void printAVL() {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    int value;

    while (cin >> value && value != -1) {
        tree.insertion(value);
    }

    int num;
    cin >> num;

    cout << tree.lowerCount(num) << endl;

    return 0;
}
