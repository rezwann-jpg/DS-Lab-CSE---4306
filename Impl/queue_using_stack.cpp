#include <bits/stdc++.h>
using namespace std;
 
struct Queue {
    stack<int> s1, s2;
    void enQueue(int x) {
        s1.push(x);
    }

    int deQueue() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }
 
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }
};