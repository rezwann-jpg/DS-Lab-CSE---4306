#include <iostream>
#include <deque>
#include <string>

int main() {
    std::string input;

    while (std::getline(std::cin, input)) {
        if (std::cin.eof()) {
            break;
        }

        std::deque<char> front_part, end_part;
        bool homeKey = false;

        for (char ch : input) {
            if (ch == '[') {
                homeKey = true;
            }
            else if (ch == ']') {
                homeKey = false;
            }
            else {
                if (homeKey) {
                    front_part.push_back(ch);
                }
                else {
                    end_part.push_back(ch);
                }
            }
        }

        for (char ch : front_part) {
            std::cout << ch;
        }
        for (char ch : end_part) {
            std::cout << ch;
        }

        std::cout << std::endl;
    }

    return 0;
}