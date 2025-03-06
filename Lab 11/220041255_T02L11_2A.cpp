#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

bool isKRegular(vector<vector<int>>& adj, int n) {
    int k = adj[1].size();

    for (int i = 2; i < n; i++) {
        if (adj[i].size() != k)
            return false;
    }

    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V + 1, vector<int>(V + 1, 0));

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (isKRegular(adj, V + 1) ? "Yes\n" : "No\n");

    return 0;
}
