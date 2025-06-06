#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void pop() {
        if (q1.empty())
            return;

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void push(int x) { q1.push(x); }

    int top() {
        if (q1.empty())
            return -1;

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int temp = q1.front();

        q1.pop();
        q2.push(temp);

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
    }

    int size() { return q1.size(); }
};