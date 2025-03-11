#include <iostream>
#define MAX 500

using namespace std;

int st[MAX][MAX];

int log2_floor(unsigned long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int query(int L, int R) {
    int width = R - L + 1;
    int j = log2_floor(width);
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        st[i][0] = arr[i];
    }

    for (int j = 1; j < log2_floor(n); j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << "\n";
    }

    return 0;
}