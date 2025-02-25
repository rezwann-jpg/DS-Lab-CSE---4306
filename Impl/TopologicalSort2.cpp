#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>

void topologicalSort(std::map<int, std::list<int>>& adjList) {
    std::map<int, int> inDegree;

    for (auto& u : adjList) {
        inDegree[u.first] = 0;
    }

    for (auto& u : adjList) {
        for (auto& v : u.second) {
            inDegree[v]++;
        }
    }

    std::queue<int> q;
    for (auto& u : inDegree) {
        if (u.second)
            q.push(u.first);
    }

    std::vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adjList[u]) {
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }

    if (topoOrder.size() != adjList.size()) {
        std::cout << "Cycle detected\n";
    }
    else {
        std::for_each(topoOrder.begin(), topoOrder.end(), [](int v){
            std::cout << v << " ";
        });
        std::cout << std::endl;
    }
}