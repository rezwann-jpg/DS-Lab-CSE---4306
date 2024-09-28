#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    int num;
    while (std::cin >> num) {
        if (num == -1)
            break;

        minHeap.push(num);
    }

    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        int sum = first + second;
        totalCost += sum;

        minHeap.push(sum);
    }

    std::cout << totalCost << std::endl;

    return 0;
}