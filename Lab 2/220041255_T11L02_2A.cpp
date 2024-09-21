#include <iostream>
#include <deque>
#include <string>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    if (S == T) {
		std::cout << "Yes. No rotation needed" << std::endl;
		return 0;
	}

    std::deque<char> dS, dT;
    for (int i = 0; i < S.size(); i++) {
        dS.push_back(S[i]);
    }

	for (int i = 0; i < T.size(); i++) {
        dT.push_back(T[i]);
    }

	if (dS.size() != dT.size()) {
		std::cout << "No" << std::endl;
		return 0;
	}



	for (int i = 1; i <= dS.size(); i++) {
		char ch = dS.back();
		dS.pop_back();
		dS.push_front(ch);
		if (dS == dT) {
			std::cout << "Yes." << " " << i << " " << "rotation required" << std::endl;
			return 0;
		}
	}

    std::cout << "No" << std::endl;
	return 0;
}
