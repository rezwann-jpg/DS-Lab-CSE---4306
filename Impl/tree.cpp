// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    Node *left, *right;
};

// Utility function to create
// a new Binary Tree Node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find the depth of
// a given node in a Binary Tree
int findDepth(Node* root, int x)
{
    // Base case
    if (root == NULL)
        return -1;

    // Initialize distance as -1
    int dist = -1;

    // Check if x is current node=
    if ((root->data == x)

        // Otherwise, check if x is
        // present in the left subtree
        || (dist = findDepth(root->left, x)) >= 0

        // Otherwise, check if x is
        // present in the right subtree
        || (dist = findDepth(root->right, x)) >= 0)

        // Return depth of the node
        return dist + 1;

    return dist;
}

// Helper function to find the height
// of a given node in the binary tree
int findHeightUtil(Node* root, int x,
                   int& height)
{
    // Base Case
    if (root == NULL) {
        return -1;
    }

    // Store the maximum height of
    // the left and right subtree
    int leftHeight = findHeightUtil(
        root->left, x, height);

    int rightHeight
        = findHeightUtil(
            root->right, x, height);

    // Update height of the current node
    int ans = max(leftHeight, rightHeight) + 1;

    // If current node is the required node
    if (root->data == x)
        height = ans;

    return ans;
}

// Function to find the height of
// a given node in a Binary Tree
int findHeight(Node* root, int x)
{
    // Store the height of
    // the given node
    int h = -1;

    // Stores height of the Tree
    int maxHeight = findHeightUtil(root, x, h);

    // Return the height
    return h;
}

void inorderTraversal(Node* root) {
  
    // Empty Tree
    if (root == nullptr)
        return;
  
    // Recur on the left subtree
    inorderTraversal(root->left);
 
    // Visit the current node
    cout << root->data << " ";
  
    // Recur on the right subtree
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    // Base case
    if (root == nullptr)
        return;
  
    // Visit the current node
    cout << root->data << " ";
  
    // Recur on the left subtree
    preorderTraversal(root->left);
  
    // Recur on the right subtree
    preorderTraversal(root->right);
}

void postorderTraversal(Node* node) {
  
    // Base case
    if (node == nullptr)
        return;
  
    // Recur on the left subtree
    postorderTraversal(node->left);
  
    // Recur on the right subtree
    postorderTraversal(node->right);
  
    // Visit the current node
    cout << node->data << " ";
}

// level order traversal 
// breadth first traversal
// bft queue file e ase

// Driver Code
int main()
{
    // Binary Tree Formation
    Node* root = newNode(5);
    root->left = newNode(10);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->left->right = newNode(25);
    root->left->right->right = newNode(45);
    root->right->left = newNode(30);
    root->right->right = newNode(35);

    int k = 25;

    // Function call to find the
    // depth of a given node
    cout << "Depth: "
         << findDepth(root, k) << "\n";

    // Function call to find the
    // height of a given node
    cout << "Height: " << findHeight(root, k);

    return 0;
}