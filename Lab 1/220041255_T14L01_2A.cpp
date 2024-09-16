#include <iostream>
#include <vector>
#include <stack>

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) 
            break;

        std::vector<int> hist(n);
        for (int i = 0; i < n; i++) {
            std::cin >> hist[i];
        }

        std::stack<int> st;
        long long int maxArea = 0;
        int N = hist.size();

        for (int i = 0; i < N; i++) {
            while (!st.empty() && hist[st.top()] > hist[i]) {
                int h = hist[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = std::max(maxArea, (long long int)h * w);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int h = hist[st.top()];
            st.pop();
            int w = st.empty() ? N : N - st.top() - 1;
            maxArea = std::max(maxArea, (long long int)h * w);
        }

        std::cout << maxArea << std::endl;
    }

    return 0;
}