#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

int main() {
    int n;
    cin >> n;
    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    vector<pair<int, int>> close;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            close.push_back({a, b});
        } else {
            merge(a, b);
        }
    }

    vector<pair<int, int>> build;
    for (int i = 2; i <= n; ++i) {
        if (find(i) != find(1)) {
            build.push_back({1, i});
            merge(1, i);
        }
    }

    cout << close.size() << endl;
    for (size_t i = 0; i < close.size(); ++i) {
        cout << close[i].first << " " << close[i].second << " "
             << build[i].first << " " << build[i].second << endl;
    }

    return 0;
}