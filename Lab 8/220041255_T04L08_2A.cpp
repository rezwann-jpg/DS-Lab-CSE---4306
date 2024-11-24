#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <unordered_map>

void Solve(const std::vector<std::vector<int>>& points) {
    if (points.size() <= 2) {
        std::cout << points.size();
        return;
    }

    int maxPoints = 0;
    std::string bestLine, lineKey;

    for (auto i : points) {
        std::unordered_map<double, int> slopeCount;
        std::unordered_map<std::string, int> lineCount;
        double x1 = i[0], y1 = i[1];

        for (auto j : points) {
            if (i == j)
                continue;

            double x2 = j[0], y2 = j[1];
            double slope, intercept;

            if (x2 - x1 == 0) {
                slope = INT_MAX;
            }
            else {
                slope = (y2 - y1) / (x2 - x1);
                intercept = y1 - slope * x1;

                lineKey = "y = " + std::to_string(slope) + "x + " + std::to_string(intercept);
            }

            lineCount[lineKey]++;
            slopeCount[slope]++;
            if (slopeCount[slope] > maxPoints) {
                maxPoints = slopeCount[slope];
            } 
        }

        for (auto& it : lineCount) {
            if (it.second == maxPoints) {
                bestLine = it.first;
            }
        }
    }

    std::cout << bestLine << "\n";
    std::cout << maxPoints + 1;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> points(N, std::vector<int>(2));

    for (int i = 0; i < N; i++) {
        std::cin >> points[i][0] >> points[i][1];
    }

    Solve(points);

    return 0;
}