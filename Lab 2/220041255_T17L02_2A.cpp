#include <iostream>
#include <queue>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::queue<int> q1, q2;
    int currentSize = 0;

    std::string command;
    while (std::cin >> command) {
        if (command == "-1") {
            break;
        }

        if (command == "push") {
            int x;
            std::cin >> x;

            if (currentSize == N) {
                std::cout << "Overflow!!" << std::endl;
            }
            else {
                q1.push(x);
                currentSize++;

                while (!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }

                std::swap(q1, q2);
            }

            std::queue<int> temp = q2;
            while (!temp.empty()) {
                std::cout << temp.front() << " ";
                temp.pop();
            }
            std::cout << std::endl;
        }
        else if (command == "pop") {
            if (currentSize == 0) {
                std::cout << "Underflow!!" << std::endl;
            }
            else {
                q2.pop();
                currentSize--;
            }

            std::queue<int> temp = q2;
            while (!temp.empty()) {
                std::cout << temp.front() << " ";
                temp.pop();
            }
            std::cout << std::endl;
        }
    }

    return 0;
}