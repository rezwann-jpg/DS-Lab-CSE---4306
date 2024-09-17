#include <iostream>
#include <queue>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void breadthFirstTraversal(TreeNode* root) {
    if (root == nullptr) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // Process the current node
        std::cout << current->val << " ";

        // Enqueue left child
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // Enqueue right child
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Breadth-First Traversal: ";
    breadthFirstTraversal(root);
    std::cout << std::endl;

    return 0;
}