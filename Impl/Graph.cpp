#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Graph {
private:
    vector<vector<int>> adjMatrix;

public:
    Graph(int n) : adjMatrix(n, vector<int>(n, 0)) {}

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void print() {
        cout << "Adjacency Matrix: " << endl;
        for (int i = 0; i < adjMatrix.size(); i++) {
            for (int j = 0; j < adjMatrix[i].size(); j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.print();

    return 0;
}