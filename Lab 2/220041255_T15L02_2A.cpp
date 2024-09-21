#include <iostream>
#include <deque>

int main() {
    int N, stone;
    std::cin >> N;

    std::deque<int> pile;
    for (int i = 0; i < N; i++) {
        std::cin >> stone;
        pile.push_back(stone);
    }

    bool DaiyansTurn = true;
    while (pile.size() > 1) {
        if (DaiyansTurn) {
            pile.push_back(pile.front());
            pile.pop_front();
            pile.pop_front();
        }
        else {
            pile.push_back(pile.front());
            pile.pop_front();
            pile.push_back(pile.front());
            pile.pop_front();
            pile.pop_front();
        }

        DaiyansTurn = !DaiyansTurn;
    }

    std::cout << (DaiyansTurn ? "Ishraq " : "Daiyan ") << pile.front() << std::endl;

    return 0;
}