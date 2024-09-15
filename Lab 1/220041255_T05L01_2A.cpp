#include <iostream>
#include <string>
#include <stack>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();

    while (N--) {
        std::string s;
        std::cin >> s;

        std::stack<char> revString;

        for (int i = 0; i < s.size(); i++) {
            revString.push(s[i]);
        }

        while (!revString.empty()) {
            std::cout << revString.top();
            revString.pop();
        }
        std::cout << std::endl;
    }

    return 0;
}