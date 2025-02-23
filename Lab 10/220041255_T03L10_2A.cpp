#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;
    int numComponents;
    int maxSize;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        numComponents = n;
        maxSize = 1;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if (parent[u] != u) {
            parent[u] = Find(parent[u]);
        }

        return parent[u];
    }

    void UnionBySize(int u, int v) {
        int rootU = Find(u);
        int rootV = Find(v);

        if (rootU != rootV) {
            if (size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
                numComponents--;
            }
            else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
                numComponents--;
            }
        }

        if (size[rootV] > maxSize) {
            maxSize = size[rootV];
        }
        else if (size[rootU] > maxSize) {
            maxSize = size[rootU];
        }
    }

    int getSize(int u) {
        return size[Find(u)];
    }

    void print() {
        cout << numComponents << " " << maxSize << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);

    int u, v;

    while (m--) {
        cin >> u >> v;
        ds.UnionBySize(u, v);
        ds.print();
    }

    return 0;
}
