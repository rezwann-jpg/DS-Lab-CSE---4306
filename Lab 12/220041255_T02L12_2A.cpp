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
    vector<int> discoveryTime;
    vector<int> finishingTime;
    vector<int> parent;
    vector<pair<int, int>> edges;
    vector<Color> colors;
    int V;
    int time;

    void DFSUtil(int u, vector<int>& DFSOrder) {
        time++;
        discoveryTime[u] = time;
        colors[u] = GRAY;
        DFSOrder.push_back(u);

        for (int v : adj[u]) {
            if (colors[v] == WHITE) {
                parent[v] = u;
                DFSUtil(v, DFSOrder);
            }
        }

        colors[u] = BLACK;
        time++;
        finishingTime[u] = time;
    }

    void printDFSOrder(vector<int>& DFSOrder) {
        for (int i : DFSOrder) {
            cout << i << " ";
        }
        cout << endl;
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V + 1);
        discoveryTime.resize(V + 1);
        finishingTime.resize(V + 1);
        parent.resize(V + 1, -1);
        colors.resize(V + 1, WHITE);
        time = 0;
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

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        edges.push_back({u, v});
    }

    void DFS() {
        vector<int> DFSOrder;

        for (int i = 1; i <= V; i++) {
            if (colors[i] == WHITE) {
                DFSUtil(i, DFSOrder);
            }
        }

        cout << "\nDFS Order: ";
        printDFSOrder(DFSOrder);
    }

    void printTimeStamps() {
        cout << "Timestamps of Vertex(discovery/finishing):" << endl;
        for (int i = 1; i <= V; i++) {
            if (discoveryTime[i] != 0) {
                cout << i << "(" << discoveryTime[i] << "/" << finishingTime[i] << ") " << endl;
            }
        }
    }

    void printEdgeClassification() {
        cout << "Edge Classification:" << endl;

        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;

            if (parent[v] == u) {
                cout << u << " " << v << " :" << "Tree Edge\n";
            } 
            else if (discoveryTime[v] < discoveryTime[u] && finishingTime[v] > finishingTime[u]) {
                cout << u << " " << v << " :" << "Back Edge\n";
            } 
            else if (discoveryTime[v] > discoveryTime[u] && finishingTime[v] < finishingTime[u]) {
                cout << u << " " << v << " :" << "Forward Edge\n";
            } 
            else {
                cout << u << " " << v << " :" << "Cross Edge\n";
            }
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    g.printAdj();
    g.DFS();
    g.printTimeStamps();
    g.printEdgeClassification();

    return 0;
}
