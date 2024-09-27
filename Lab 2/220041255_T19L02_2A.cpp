#include <iostream>
#include <queue>
#include <vector>
#include <stack>

int main() {
    int N;
    std::cin >> N;

    std::queue<int> students;
    std::vector<int> dishesInput(N);
    std::stack<int> dishes;

    for (int i = 0; i < N; i++) {
        int s;
        std::cin >> s;
        students.push(s);
    }

    for (int i = 0; i < N; i++) {
        std::cin >> dishesInput[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        dishes.push(dishesInput[i]);
    }

    int unableToEat = 0;
    bool flag = false;

    while (!students.empty() && !flag) {
        if (students.front() == dishes.top()) {
            students.pop();
            dishes.pop();
            unableToEat = 0;
        }
        else {
            unableToEat++;
            students.push(students.front());
            students.pop();
        }

        if (unableToEat == students.size())
            break;
    }

    std::cout << students.size() << std::endl;

    return 0;
}