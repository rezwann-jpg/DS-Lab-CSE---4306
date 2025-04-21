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

    for (int i = 1; i <= n; i++) {
        log2_val[i] = log2_floor(i);
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    cout << "Ranges to be stored in Sparse Table:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; (1 << j) <= n - i; j++) {
            cout << "(" << i << "," << i + (1 << j) - 1 << ") ";
        }
        cout << endl;
    }

    cout << "\nStatus of Sparse Table:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; (1 << j) <= n - i; j++) {
            cout << st[i][j] << " ";
        }
        cout << endl;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        cout << "Query-" << i + 1 << ": Min=" << query(L, R) << " min(["
             << L << "," << L + (1 << log2_val[R - L + 1]) - 1 << "], ["
             << R - (1 << log2_val[R - L + 1]) + 1 << "," << R << "])" << endl;
    }

    return 0;
}
