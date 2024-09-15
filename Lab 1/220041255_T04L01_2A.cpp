#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::vector<int> nums;
    int num;

    while (std::cin >> num && num != -1) {
        nums.push_back(num);
    }

    std::stack<int> s;

    int n = nums.size();
    std::vector<int> result(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }

        if (!s.empty()) {
            result[i] = s.top();
        }

        s.push(nums[i]);
    }

    for (int it : result) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}