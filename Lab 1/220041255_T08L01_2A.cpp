#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']');
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    
    std::vector<std::string> lines(N);
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, lines[i]);
    }

    std::stack<char> checkCode;
    bool errorFound = false;

    for (std::string line : lines) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '(' || line[i] == '{' || line[i] == '[') {
                checkCode.push(line[i]);
            }
            else if (line[i] == ')' || line[i] == '}' || line[i] == ']') {
                if (checkCode.empty() || !isMatchingPair(checkCode.top(), line[i])) {
                    errorFound = true;
                }
                checkCode.pop();
            }
        }
    }

    if (!checkCode.empty() || errorFound) {
        std::cout << "Error" << std::endl;
    }
    else {
        std::cout << "No Errors" << std::endl;
    }
    
    return 0;
}