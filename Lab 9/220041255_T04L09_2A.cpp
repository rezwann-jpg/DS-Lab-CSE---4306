#include <iostream>
#include <cmath>

struct Node {
    Node *left;
    Node *right;
};

class Solution {
private:
    Node *head;

public:
    Solution() {
        head = new Node();
    }

    void Insert(int key) {
        Node *curr = head;

        for (int i = 30; i >= 0; i--) {
            int ithBit = (key >> i) & 1;

            if (ithBit == 0) {
                if (!curr->left)
                    curr->left = new Node();

                curr = curr->left;
            }
            else {
                if (!curr->right)
                    curr->right = new Node();

                curr = curr->right;
            }
        }
    }

    int Solve(int arr[], int n) {
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int currentXOR = 0;

            int M = std::pow(2, 30);

            Node *curr = head;

            for (int j = 30; j >= 0; j--) {
                int ithBit = (arr[i] >> j) & 1;

                if (ithBit == 0) {
                    if (curr->right) {
                        currentXOR += M;
                        curr = curr->right;
                    }
                    else {
                        curr = curr->left;
                    }
                }
                else {
                    if (curr->left) {
                        currentXOR += M;
                        curr = curr->left;
                    }
                    else {
                        curr = curr->right;
                    }
                }

                M /= 2;
            }

            ans = std::max(ans, currentXOR);
        }

        return ans;
    }
};

int main () {
    Solution sol;

    int arr[] = {3, 10, 5, 25, 2, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        sol.Insert(arr[i]);
    }

    std::cout << sol.Solve(arr, n) << std::endl;

    return 0;
}

/*
{3, 10, 5, 25, 2, 8}
{0, 1, 2, 3, 4}
{8, 1, 2, 15}
{1, 1, 1, 1}
{5, 25, 10, 2, 8, 12}
{0}
*/
