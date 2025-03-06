#include <iostream>
#include <vector>
#include <list>
#include <map>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Graph {
private:
    vector<vector<int>> adjMatrix;

public:
    Graph(int n) : adjMatrix(n + 1, vector<int>(n + 1, 0)) {}

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void print() {
        cout << "Adjacency Matrix: " << endl;
        for (int i = 1; i < adjMatrix.size(); i++) {
            for (int j = 1; j < adjMatrix[i].size(); j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Graph2 {
private:
    std::map<int, std::list<int>> adjList;

public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void print() {
        std::cout << "Adjacency list: " << std::endl;
        for (auto& i : adjList) {
            std::cout << i.first << ": ";
            for (auto& j : i.second) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    int V, E;
    cin >> V >> E;

    Graph2 g2;
    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        g2.addEdge(u, v);
        g.addEdge(u, v);
    }

    g2.print();
    g.print();

    return 0;
}
