struct Node {
    int value;
    int height;

    Node *left;
    Node *right;
    Node *parent;

    Node (int val) : value(val), height(0), left(nullptr), right(nullptr), parent(nullptr) { }
};

class AVL {
private:
    Node *root;

    int getMax(int a, int b) {
        return (a > b) ? a : b;
    }

    int getHeight(Node* node) {
        return node ? node->height : -1;
    }

    int getBalanceFactor(Node *node) {
        return getHeight(node->left) - getHeight(node->right);
    }

    Node *leftRotate(Node *x) {
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

        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node *rightRotate(Node *x) {
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
        
        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node *balanceNode(Node *node) {
        int balance = getBalanceFactor(node);

        if (balance > 1 && getBalanceFactor(node->left) >= 0)
            return rightRotate(node);
        else if (balance < -1 && getBalanceFactor(node->right) < 0)
            return leftRotate(node);
        else if (balance > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        else if (balance < -1 && getBalanceFactor(node->right) > 0) {
            node->right = leftRotate(node->right);
            return leftRotate(node);
        }
    }

    Node *Insert(Node *node, int value) {
        Node *parent = nullptr;
        Node *current = node;
        Node *newNode = new Node(value);

        if (!current) {
            return newNode;
        }

        while (current) {
            parent = current;
            if (value < current->value) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        newNode->parent = parent;

        if (value < parent->value) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }

        current = newNode->parent;

        while (current) {
            current->height = getMax(getHeight(current->left), getHeight(current->right)) + 1;
            current = current->parent;
        }

        current = newNode->parent;

        while (current) {
            current = balanceNode(current);
            current = current->parent;
        }

        while (root && root->parent) {
            root = root->parent;
        }

        return root;
    }
public:
    AVL() : root(nullptr) { }

    void Insert(int value) {
        root = Insert(root, value);
    }
};