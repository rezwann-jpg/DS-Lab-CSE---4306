#include <iostream>
#include <vector>
#include <stack>
#include <string>

int main() {
    std::vector<int> targetArray;
    int num;

    while (std::cin >> num && num != -1) {
        targetArray.push_back(num);
    }

    std::stack<std::string> operations;

    int currentElement = 1;
    for (int target : targetArray) {
        while (currentElement < target) {
            operations.push("Push");
            operations.push("Pop");
            currentElement++;
        }
        operations.push("Push");
        currentElement++;
    }

    std::stack<std::string> tempStack;
    while (!operations.empty()) {
        tempStack.push(operations.top());
        operations.pop();
    }

    operations = tempStack;

    while (!operations.empty()) {
        std::cout << operations.top() << " ";
        operations.pop();
    }

    return 0;
}