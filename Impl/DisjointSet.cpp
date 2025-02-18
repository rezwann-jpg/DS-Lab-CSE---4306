#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

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
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
    
    void UnionBySize(int u, int v) {
        int rootU = Find(u);
        int rootV = Find(v);

        if (rootU != rootV) {
            if (size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            }
            else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    }

    int getSize(int u) {
        return size[Find(u)];
    }

    void printSets() {
        for (int i = 0; i < parent.size(); i++) {
            cout << "Element: " << i << ", Parent: " << parent[i] << endl;
        }
    }
};

int main() {
    DisjointSet ds(7);

    // ds.Union(0, 1);
    // ds.Union(1, 2);
    // ds.Union(3, 4);
    // ds.Union(5, 6);
    // ds.Union(4, 5);
    // ds.Union(2, 6);
    
    ds.printSets();

    return 0;
}