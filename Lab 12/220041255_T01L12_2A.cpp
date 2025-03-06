#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK
};

class Graph {
private:
    vector<vector<int>> adj;
    int V;

    void printDist(vector<int>& dist) {
        cout << "Distance from source: " << endl;
        for (int i = 1; i <= V; i++) {
            if (dist[i] != -1) {
                cout << i << "(" << dist[i] << ") ";
            }
        }
        cout << endl;
    }

    void printPath(vector<int>& parent, int s, int d) {
        if (s == d) {
            cout << s;
            return;
        }
        else if (parent[d] == -1) {
            cout << " ";
            return;
        }
        else {
            printPath(parent, s, parent[d]);
            cout << "->" << d;
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printAdj() {
        cout << "Adjacency list: " << endl;

        for (int i = 1; i <= V; i++) {
            cout << i << ":";
            for (int j : adj[i]) {
                cout << " " << j;
            }
            cout << endl;
        }
    }

    void BFS(int s) {
        vector<int> dist(V + 1, -1);
        vector<int> parent(V + 1, -1);
        vector<Color> colors(V + 1, WHITE);
        queue<int> q;

        dist[s] = 0;
        colors[s] = GRAY;
        q.push(s);

        vector<int> bfsOrder;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            bfsOrder.push_back(u);

            for (int v : adj[u]) {
                if (colors[v] == WHITE) {
                    colors[v] = GRAY;
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
            colors[u] = BLACK;
        }

        cout << "BFS Order: ";
        for (int node : bfsOrder) {
            cout  << node << " ";
        }
        cout << endl;

        printDist(dist);

        cout << "Paths from source: " << endl;
        for (int i = 1; i <= V; i++) {
            cout << i << ": ";
            printPath(parent, s, i);
            cout << endl;
        }
        cout << endl;

        cout << "Edges of BFS tree: " << endl;
        for (int i = 1; i <= V; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " " << i << endl;
            }
        }
    }
};

int main() {
    int V, E, s;

    cin >> V >> E >> s;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    g.printAdj();
    g.BFS(s);

    return 0;
}
