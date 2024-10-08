#include <iostream>
using namespace std;

// Definition of the node structure with parent pointer
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent; // Pointer to the parent node

    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

// Definition of the Binary Search Tree class
class BST {
private:
    Node* root;

    // Function to replace one subtree rooted at node u with another subtree rooted at node v
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {  // u is the root node
            root = v;
        } else if (u == u->parent->left) {  // u is a left child
            u->parent->left = v;
        } else {  // u is a right child
            u->parent->right = v;
        }

        if (v != nullptr) {  // Set parent pointer of v
            v->parent = u->parent;
        }
    }

public:
    // Constructor to initialize an empty tree
    BST() {
        root = nullptr;
    }

    // Iterative insertion function
    void insert(int value) {
        // Create the new node to be inserted
        Node* newNode = new Node(value);

        // If the tree is empty, set the new node as the root
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* target = nullptr;

        // Traverse the tree to find the correct insertion point
        while (current != nullptr) {
            target = current; // Keep track of the parent node

            if (newNode->data < current->data) {
                // Move to the left child
                current = current->left;
            } else if (newNode->data > current->data) {
                // Move to the right child
                current = current->right;
            }
        }

        // Set the parent pointer of the new node
        newNode->parent = target;

        // Insert the new node as a child of the found parent
        if (newNode->data < target->data) {
            target->left = newNode;
        } else {
            target->right = newNode;
        }
    }

    // In-order traversal to print the tree
    void inorderTraversal() const {
        inorderTraversalHelper(root);
        cout << endl;
    }

    // Helper function for in-order traversal (recursive)
    void inorderTraversalHelper(Node* node) const {
        if (node == nullptr) {
            return;
        }

        inorderTraversalHelper(node->left);  // Visit the left subtree
        cout << node->data << " ";          // Visit the root
        inorderTraversalHelper(node->right); // Visit the right subtree
    }

    // Function to get the root node (for testing purposes)
    Node* getRoot() const {
        return root;
    }

     // Iterative search function
    Node* searchIterative(int value) const {
        Node* current = root;

        while (current != nullptr) {
            if (current->data == value) {
                return current;  // Node found
            } else if (value < current->data) {
                current = current->left;  // Go to the left subtree
            } else {
                current = current->right;  // Go to the right subtree
            }
        }

        return nullptr;  // Node not found
    }

    // Iterative function to find the minimum value node
    Node* findMinIterative() const {
        if (root == nullptr) {
            return nullptr;  // Tree is empty
        }

        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;  // Keep moving to the leftmost node
        }

        return current;  // This is the minimum node
    }

    // Iterative function to find the maximum value node
    Node* findMaxIterative() const {
        if (root == nullptr) {
            return nullptr;  // Tree is empty
        }

        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;  // Keep moving to the rightmost node
        }

        return current;  // This is the maximum node
    }

    // Function to find the minimum node in a subtree (leftmost node)
    Node* findMin(Node* node) const {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Function to find the in-order successor of a given node
    Node* findInOrderSuccessor(Node* node) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (node == findMaxIterative()) {
            return nullptr;
        }

        // Case 1: If the node has a right subtree, the successor is the leftmost node in the right subtree
        if (node->right != nullptr) {
            return findMin(node->right);
        }

        // Case 2: If there's no right subtree, move up using the parent pointer
        Node* parent = node->parent;
        while (parent != nullptr && node == parent->right) {
            node = parent;   // Move up the tree
            parent = parent->parent;
        }

        return parent;  // This is the in-order successor
    }

    // Recursive function to calculate the size of a subtree rooted at a given node
    int getSubtreeSize(Node* node) const {
        if (node == nullptr) {
            return 0;  // Base case: If the node is null, the subtree size is 0
        }

        // The size of the subtree is 1 (the node itself) + size of left subtree + size of right subtree
        return 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }

    // Function to delete a node with a given value using the transplant method
    void deleteNode(int value) {
        Node* nodeToDelete = searchIterative(value);
        if (nodeToDelete == nullptr) {
            return;  // Node to delete not found
        }

        // Case 1: Node to delete has no left child
        if (nodeToDelete->left == nullptr) {
            transplant(nodeToDelete, nodeToDelete->right);
        }
        // Case 2: Node to delete has no right child
        else if (nodeToDelete->right == nullptr) {
            transplant(nodeToDelete, nodeToDelete->left);
        }
        // Case 3: Node to delete has both left and right children
        else {
            // Find the in-order successor (smallest node in the right subtree)
            Node* successor = findMin(nodeToDelete->right);

            // If successor is not the direct right child of node to delete
            if (successor->parent != nodeToDelete) {
                transplant(successor, successor->right);
                successor->right = nodeToDelete->right;
                successor->right->parent = successor;
            }

            // Replace node to delete with its successor
            transplant(nodeToDelete, successor);
            successor->left = nodeToDelete->left;
            successor->left->parent = successor;
        }

        delete nodeToDelete;  // Free memory of the deleted node
    }
};

int main() {
    BST tree;

    // Insert nodes into the BST using the iterative insertion method
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Print the in-order traversal of the BST
    cout << "In-order traversal of the BST: ";
    tree.inorderTraversal();

    return 0;
}