#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

unordered_map<string, vector<string>> graph;
unordered_map<string, int> inDegree;
vector<string> students;

vector<string>
topologicalSort() {
    queue<string> q;

    for (const string& student : students) {
        if (inDegree[student] == 0) {
            q.push(student);
        }
    }

    vector<string> order;
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        order.push_back(u);

        for (const string& v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (order.size() == students.size()) {
        return order;
    }
    else {
        return {};
    }
}

int main() {
    int V, E, Q;
    cin >> V >> E >> Q;

    students.resize(V);

    for (int i = 0; i < V; i++) {
        cin >> students[i];
    }

    for (const string& student : students) {
        graph[student] = {};
        inDegree[student] = 0;
    }

    for (int i = 0; i < E; i++) {
        string u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    vector<string> order = topologicalSort();

    if (order.empty()) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (const string& student : order) {
            cout << student << " ";
        }
        cout << "\n";

        unordered_map<string, int> position;
        for (int i = 0; i < order.size(); i++) {
            position[order[i]] = i;
        }

        for (int i = 0; i < Q; i++) {
            string u, v;
            cin >> u >> v;
            if (position[u] > position[v]) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}