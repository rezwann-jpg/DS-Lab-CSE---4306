#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();

    std::stack<std::string> tagStack;
    std::vector<std::string> lines(N);
    // bool errorFound = false;

    for (int i = 0; i < N; i++) {
        std::getline(std::cin, lines[i]);
    }

    for (int i = 0; i < lines.size(); i++) {
        const std::string& line = lines[i];
        size_t pos = 0;

        while (pos < line.length()) {
            size_t tagStart = line.find('<', pos);
            if (tagStart == std::string::npos)
                break;

            size_t tagEnd = line.find('>', tagStart);
            if (tagEnd == std::string::npos) {
                std::cout << "Error at line " << i + 1 << std::endl;
                return 0;
            }

            std::string tag = line.substr(tagStart, tagEnd - tagStart + 1);

            if (tag[1] != '/') {
                tagStack.push(tag.substr(1, tag.find_first_of('>', 1)));
            }
            else {
                std::string closingTag = tag.substr(2, tag.find_first_of('>', 2));
                if (tagStack.empty()) {
                    std::cout << "Error at line " << i + 1 << std::endl;
                    return 0;
                }
                if (tagStack.top() != closingTag) {
                    std::cout << "Error at line " << i + 1 << std::endl;
                    return 0;
                }
                tagStack.pop();
            }

            pos = tagEnd + 1;
        }
    }

    if (!tagStack.empty()) {
        std::cout << "Error at line " << N << std::endl;
    }

    std::cout << "No error" << std::endl;

    return 0;
}