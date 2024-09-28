#include <iostream>
#include <queue>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int i = 0; i < N; i++) {
        minHeap.push(arr[i]);

        if (minHeap.size() > 3) 
            minHeap.pop();


        if (minHeap.size() < 3) {
            std::cout << -1 << std::endl;
        }
        else {
            std::vector<int> temp;
            while (!minHeap.empty()) {
                temp.push_back(minHeap.top());
                minHeap.pop();
            }

            for (int val : temp) {
                minHeap.push(val);
            }

            int product = temp[0] * temp[1] * temp[2];
            std::cout << product << std::endl;
        }
    }

    return 0;
}