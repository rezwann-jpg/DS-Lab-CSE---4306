#include <iostream>
#include <stack>
#include <string>

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']');
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();

    while (N--) {
        std::string line;
        std::getline(std::cin, line);

        std::stack<char> checkExp;
        bool flag = true;

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '(' || line[i] == '{' || line[i] == '[') {
                checkExp.push(line[i]);
            }
            else if (line[i] == ')' || line[i] == '}' || line[i] == ']') {
                if (checkExp.empty() || !isMatchingPair(checkExp.top(), line[i])) {
                    std::cout << "No" << std::endl;
                    flag = false;
                    break;
                }
                checkExp.pop();
            }
        }

        if (!checkExp.empty()) {
            std::cout << "No" << std::endl;
        }
        else if (flag) {
            std::cout << "Yes" << std::endl;
        }   
    }

    return 0;
}