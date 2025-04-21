#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 500

using namespace std;

int st[MAX][MAX];
int log2_val[MAX];

int log2_floor(unsigned long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int query(int L, int R) {
    int width = R - L + 1;
    int j = log2_val[width];
    return max(st[L][j], st[R - (1 << j) + 1][j]);
}

void build(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        log2_val[i] = log2_floor(i);
    }

    for (int i = 1; i <= n; i++) {
        st[i][0] = arr[i];
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(arr, n);

    int ans = 0;

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        if (abs(a - b) <= 1)
            ans++;
        else {
            int mx = query(a + 1, b - 1);
            if (mx <= arr[a])
                ans++;
        }
    }

    cout << ans << "\n";
}
