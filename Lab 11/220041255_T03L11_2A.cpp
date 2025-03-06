#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::queue;
using std::cout;
using std::cin;
using std::endl;

void addEdge(vector<vector<int>>& adjMat, int u, int v) {
    adjMat[u][v] = 1;
}

void topologicalSort(vector<vector<int>>& adjMat, int V) {
    vector<int> inDegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adjMat[i][j]) {
                inDegree[j]++;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v = 0; v < V; v++) {
            if (adjMat[u][v]) {
                if (--inDegree[v] == 0)
                    q.push(v);
            }
        }
    }

    if (topoOrder.size() != V) {
        std::cout << "[ ]\n";
    }
    else {
        std::for_each(topoOrder.begin(), topoOrder.end(), [](int v){
            cout << v << " ";
        });
        cout << endl;
    }
}


int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adjMat(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        addEdge(adjMat, u, v);
    }

    topologicalSort(adjMat, V);

    return 0;
}
