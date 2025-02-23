#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


class DisjointSet {
private:
    vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if (parent[u] == u)
            return u;

        return Find(parent[u]);
    }

    void Union(int u, int v) {
        int uRep = Find(u);
        int vRep = Find(v);

        if (uRep != vRep) {
            parent[vRep] = uRep;
        }
    }

    void printSets() {
        for (int i = 0; i < parent.size(); i++) {
            cout << parent[i] << " ";
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
            ds.Union(i, j);
            ds.printSets();
            break;
        }
    }

    return 0;
}
