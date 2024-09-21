#include <iostream>
#include <stack>

int main()
{
    int N, q, choice, x;
    std::stack<int> s1, s2;

    std::cin >> N >> q;

    while (q--) {
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cin >> x;
            if (s1.size() == N) {
                std::cout << "Size: " << N << " Elements: Overflow!" << std::endl;
                break;
            }
            s1.push(x);
            std::cout << "Size: " << s1.size() << " Elements: ";
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            while (!s2.empty()) {
                std::cout << s2.top() << " ";
                s1.push(s2.top());
                s2.pop();
            }
            std::cout << std::endl;
            break;
        case 2:
            if (s1.empty()) {
                std::cout << "Size: 0 Elements: Underflow!" << std::endl;
                break;
            }
            else {
                s1.pop();
                std::cout << "Size: ";
                std::cout << s1.size() << " Elements: ";
                if (s1.empty()) {
                    std::cout << "NULL" << std::endl;
                    break;
                }
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                while (!s2.empty()) {
                    std::cout << s2.top() << " ";
                    s1.push(s2.top());
                    s2.pop();
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}