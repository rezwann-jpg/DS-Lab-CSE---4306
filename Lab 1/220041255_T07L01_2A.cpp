#include <iostream>
#include <stack>
#include <string>

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore();

    while (T--) {
        std::string line;
        std::getline(std::cin, line);

        std::stack<int> polishNot;

        for (int i = 0; i < line.size(); i++) {
            if (std::isdigit(line[i])) {
                polishNot.push(line[i] - '0');
            }
            else {
                int val1 = polishNot.top();
                polishNot.pop();
                int val2 = polishNot.top();
                polishNot.pop();

                int result;

                switch (line[i]) {
                    case '+':
                        result = val1 + val2;
                        break;

                    case '-':
                        result = val2 - val1;
                        break;

                    case '*':
                        result = val1 * val2;
                        break;

                    case '/':
                        result = val1 / val2;
                        break;
                }

                polishNot.push(result);
            }
        }

        std::cout << polishNot.top() << std::endl;
    }

    return 0;
}