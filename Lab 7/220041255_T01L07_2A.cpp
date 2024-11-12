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

class AVL {
private:
    Node* root;

    void inorderTraversal(Node *node);
    void updateAncestorHeight(Node *node);
    void updateHeight(Node* node);
    void leftRotate(Node* x);
    void rightRotate(Node* x);
    int getBalanceFactor(Node* node);

public:
    AVL() : root(nullptr) {}

    void Insert(int value);
    void Print_tree();
    int getHeight(Node *node);
};

void AVL::updateAncestorHeight(Node *node) {
    Node *temp = node;
    while (temp) {
        updateHeight(temp);
        temp = temp->parent;
    }
}
/*
void AVL::leftRotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;

    if (y->left)
        y->left->parent = x;

    if (x == root)
        root = y;
    y->parent = x->parent;

    if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;

    updateAncestorHeight(x);
}

void AVL::rightRotate(Node *x) {
    Node *y = x->left;
    x->left = y->right;

    if (y->right) {
        y->right->parent = x;
    }

    if (x == root)
        root = y;
    y->parent = x->parent;

    if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;
    x->parent = y;

    updateAncestorHeight(x);
}
*/
void AVL::updateHeight(Node *node) {
    if (node) {
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }
}

int AVL::getBalanceFactor(Node *node) {
    if (!node)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

void AVL::Insert(int value) {
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

    updateAncestorHeight(newNode);

/*

    Node *temp = newNode;

    while (temp) {
        int b_fact = getBalanceFactor(temp);

        if (b_fact < -1 || b_fact > 1) {
            if (b_fact > 1) {
                if (newNode->data < temp->left->data) {
                    rightRotate(temp);
                }
                if (newNode->data > temp->left->data) {
                    leftRotate(temp->left);
                    rightRotate(temp);
                }
            }
            if (b_fact < -1) {
                if (newNode->data > temp->right->data) {
                    leftRotate(temp);
                }
                if (newNode->data < temp->right->data) {
                    rightRotate(temp->right);
                    leftRotate(temp);
                }
            }
        }
        else {
            temp = temp->parent;
        }
    }

    std::cout << "Case 1";
    */
}

void AVL::Print_tree() {
    if (root == nullptr) {
        std::cout << "Tree is empty.";
        return;
    }
    inorderTraversal(root);
    std::cout << std::endl;
}

void AVL::inorderTraversal(Node *node) {
    if (!node)
        return;

    inorderTraversal(node->left);
    std::cout << node->data << "(";
    std::cout << getBalanceFactor(node) << ") ";
    inorderTraversal(node->right);
}

int AVL::getHeight(Node *node) {
    if (!node)
        return -1;

    return node->height;
}


int main() {
    AVL tree;

    int num;
    while (std::cin >> num && num != -1) {
        tree.Insert(num);
        tree.Print_tree();
    }

    return 0;
}
