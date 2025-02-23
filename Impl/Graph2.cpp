#include <iostream>
#include <list>
#include <map>

class Graph {
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
            std::cout << i.first << " -> ";
            for (auto& j : i.second) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g;

    g.addEdge(1, 0);
    g.addEdge(2, 0);
    g.addEdge(1, 2);

    g.print();

    return 0;
}