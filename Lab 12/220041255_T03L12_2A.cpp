#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<string>> adj;
unordered_map<string, bool> visited;
unordered_map<string, string> parent;

bool dfs(string current, string dst) {
    if (current == dst) return true;

    visited[current] = true;

    for (string neighbor : adj[current]) {
        if (!visited[neighbor]) {
            parent[neighbor] = current;
            if (dfs(neighbor, dst)) 
                return true;
        }
    }

    return false;
}

vector<string> getPath(string src, string dst) {
    vector<string> path;
    string current = dst;

    while (current != src) {
        path.push_back(current);
        current = parent[current];
        if (current.empty()) 
            return {};
    }

    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int V, E, Q;
    cin >> V >> E >> Q;

    vector<string> cities(V);

    for (int i = 0; i < V; ++i) {
        cin >> cities[i];
    }

    for (int i = 0; i < E; ++i) {
        string u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (Q--) {
        string src, dst;
        int k;
        cin >> src >> dst >> k;
        visited.clear();
        parent.clear();

        if (!dfs(src, dst)) {
            cout << "NO\n";
            continue;
        }

        vector<string> path = getPath(src, dst);
        int edges = path.size() - 1;

        if (k == 0) {
            if (edges == 0) {
                cout << src << endl;
            } else {
                cout << "NO\n";
            }
            continue;
        }

        if (edges % (k + 1) != 0) {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < path.size(); i += k + 1) {
            if (i != 0) 
                cout << " ";
            cout << path[i];
        }
        cout << endl;
    }

    return 0;
}