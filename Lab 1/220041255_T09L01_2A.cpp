#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string S;
    std::cin >> S;

    std::stack<char> charStack;

    for (int i = 0; i < S.size(); i++) {
        if (!charStack.empty() && charStack.top() == S[i]) {
            charStack.pop();
        }
        else {
            charStack.push(S[i]);
        }
    }

    std::stack<char> revStack;
    while (!charStack.empty()) {
        revStack.push(charStack.top());
        charStack.pop();
    }

    charStack = revStack;
    while (!charStack.empty()) {
        std::cout << charStack.top();
        charStack.pop();
    }
    std::cout << std::endl;
    return 0;
}