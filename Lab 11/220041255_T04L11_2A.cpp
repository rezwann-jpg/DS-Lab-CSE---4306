#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

bool hasPath(int s, int d) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == d) {
            return true;
        }

        for (int u : graph[curr]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int src, dest;
    cin >> src >> dest;

    cout << (hasPath(src, dest) ? "Yes\n" : "No\n");

    return 0;
}