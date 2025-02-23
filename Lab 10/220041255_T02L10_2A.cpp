#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if (parent[u] != u) {
            parent[u] = Find(parent[u]);
        }

        return parent[u];
    }

    void UnionByRank(int u, int v) {
        int rootU = Find(u);
        int rootV = Find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            }
            else {
                parent[rootU] = rootV;
                rank[rootV]++;
            }
        }
    }

    void printSets() {
        for (int i = 0; i < parent.size(); i++) {
            cout << parent[i] << "(" << rank[i] << ") ";
        }
        cout << endl;
    }
};

int main() {
    int N;
    cin >> N;

    DisjointSet ds(N);

    int input;
    int i, j;

    while (cin >> input && input != -1) {
        switch (input) {
        case 1:
            ds.printSets();
            break;

        case 2:
            cin >> i;
            cout << ds.Find(i) << endl;
            break;

        case 3:
            cin >> i >> j;
            ds.UnionByRank(i, j);
            ds.printSets();
            break;

        case 4:
            ds.printSets();
            break;
        }
    }

    return 0;
}
