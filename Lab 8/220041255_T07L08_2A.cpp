#include <iostream>
#include <string>
#include <unordered_set>

typedef long long int i64;

const i64 BASE = 347;
const i64 MOD = 1e9 + 7;
const int SEQUENCE_LENGTH = 10;

i64 hash_function(const std::string& s, int m) {
    i64 hash = 0, power = 1;

    for (int i = m - 1; i >= 0; i--) {
        hash = hash + (s[i] * power) % MOD;
        hash = hash % MOD;
        power = (power * BASE) % MOD;
    }

    return hash;
}

void Solve(const std::string& s) {
    if (s.size() <= SEQUENCE_LENGTH) {
        return;
    }

    int n = s.size();

    i64 power = 1;
    for (int i = 1; i < SEQUENCE_LENGTH; i++) {
        power = (power * BASE) % MOD;
    }

    i64 hash_value = hash_function(s, SEQUENCE_LENGTH);

    std::unordered_set<i64> seenHashes;
    std::unordered_set<std::string> result;
    seenHashes.insert(hash_value);

    for (int i = SEQUENCE_LENGTH; i < n; i++) {
        hash_value = (hash_value - (power * s[i - SEQUENCE_LENGTH]) % MOD) % MOD;
        hash_value = (hash_value + MOD) % MOD;
        hash_value = (hash_value * BASE) % MOD;
        hash_value = (hash_value + s[i]) % MOD;

        std::string substring = s.substr(i - SEQUENCE_LENGTH + 1, SEQUENCE_LENGTH);
        if (seenHashes.count(hash_value)) {
            result.insert(substring);
        }
        else {
            seenHashes.insert(hash_value);
        }
    }

    std::unordered_set<std::string>::iterator it;
    for (it = result.begin(); it != result.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    Solve(input);

    return 0;
}