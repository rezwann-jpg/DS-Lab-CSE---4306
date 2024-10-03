#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::vector<int> stones;
    int num;

    while (std::cin >> num) {
        if (num == -1)
            break;

        stones.push_back(num);
    }

    std::priority_queue<int> maxHeap;

    for (int stone: stones) {
        maxHeap.push(stone);
    }

    while (maxHeap.size() > 1) {
        int y = maxHeap.top();
        maxHeap.pop();
        int x = maxHeap.top();
        maxHeap.pop();

        if (y != x) {
            maxHeap.push(y - x);
        }
    }

    std::cout << maxHeap.top() << std::endl;

    return 0;
}