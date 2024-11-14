#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>

void Solve(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> countMap;
    std::vector<std::pair<int, int>> pairs;

    for (int i = 0; i < nums.size(); i++) {
        countMap[nums[i]]++;
    }

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (countMap[complement] > 0) {
            if (nums[i] == complement && countMap[nums[i]] > 1) {
                pairs.push_back(std::make_pair(nums[i], complement));
                countMap[nums[i]] -= 2;
            }
            else if (nums[i] != complement && countMap[nums[i]] > 0 && countMap[complement] > 0) {
                pairs.push_back(std::make_pair(nums[i], complement));
                countMap[nums[i]]--;
                countMap[complement]--;
            }
        }
    }

    if (!pairs.empty()) {
        for (int i = 0; i < pairs.size(); i++) {
            std::cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No pairs found" << std::endl;
    }
}

int main() {
    std::vector<int> numbers;
    int num, target;

    while (std::cin >> num && num != -1) {
        numbers.push_back(num);
    }

    std::cin >> target;

    Solve(numbers, target);

    return 0;
}
