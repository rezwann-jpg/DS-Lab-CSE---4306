#include <iostream>
#include <deque>
#include <vector>

int main() {
    int n;
    
    while (std::cin >> n && n != 0) {
        std::deque<int> deck;
        std::vector<int> discarded;

        for (int i = 1; i <= n; i++) {
            deck.push_back(i);
        }

        while (deck.size() > 1) {
            discarded.push_back(deck.front());
            deck.pop_front();

            int top_card = deck.front();
            deck.pop_front();
            deck.push_back(top_card);
        }

        int rem_card = deck.front();

        std::cout << "Discarder cards: ";
        for (int i = 0; i < discarded.size(); i++) {
            if (i > 0) {
                std::cout << ", ";
            }
            std::cout << discarded[i];
        }

        std::cout << std::endl;

        std::cout << "Remaining card: " << rem_card << std::endl;
    }

    return 0;
}