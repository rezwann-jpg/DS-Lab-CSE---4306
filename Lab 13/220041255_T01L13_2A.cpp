#include <iostream>
#include <cstring>
#include <string>
#define MAX_LEN 1005
#define MAX_CHAR 26

using namespace std;

int freq[MAX_LEN][MAX_CHAR];

void preprocess(string& s) {
    int n = s.length();

    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; i++) {
        freq[i][s[i] - 'a']++;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            freq[i][j] += freq[i - 1][j];
        }
    }
}

char bestChar(int L, int R) {
    int maxFreq = 0;
    char c = 'z';

    for (int j = 0; j < 26; j++) {
        int count = freq[R][j] - freq[L - 1][j];
        if (count > maxFreq || (count == maxFreq && (char)('a' + j) < c)) {
            maxFreq = count;
            c = 'a' + j;
        }
    }

    return c;
}

int main() {
    string s;
    cin >> s;

    preprocess(s);

    int q;
    cin >> q;

    while (q--) {
        int L, R;
        cin >> L >> R;
        L--;R--;
        cout << bestChar(L, R) << "\n";
    }

    return 0;
}
