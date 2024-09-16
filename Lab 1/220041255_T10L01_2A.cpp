#include <iostream>
#include <vector>
#include <stack>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::stack<int> st;
    int need = 1;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() == need) {
            need++;
            st.pop();
        }

        if (arr[i] == need) {
            need++;
        }
        else if (!st.empty() && st.top() < arr[i]) {
            flag = false;
            break;
        }
        else {
            st.push(arr[i]);
        }
    }

    if (flag) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    return 0;
}