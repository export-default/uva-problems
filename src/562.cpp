#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// https://uva.onlinejudge.org/external/5/562.html


int knapsack(const std::vector<int> &coins, int value) {

    std::vector<std::vector<int>> k(coins.size() + 1, std::vector<int>(value + 1));

    for (int i = 0; i <= coins.size(); ++i) {
        for (int j = 0; j <= value; ++j) {
            if (i == 0 || j == 0) {
                k[i][j] = 0;
            } else {
                int v = coins[i - 1];
                if (v > j) {
                    k[i][j] = k[i - 1][j];
                } else {
                    k[i][j] = std::max(v + k[i - 1][j - v], k[i - 1][j]);
                }
            }
        }
    }

    return k[coins.size()][value];
}

int main() {
    int ncase;
    std::cin >> ncase;

    for (int i = 0; i < ncase; ++i) {
        int n;
        std::cin >> n;
        std::vector<int> coins(n);
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            std::cin >> coins[j];
            sum += coins[j];
        }

        int a = knapsack(coins, sum / 2);

        std::cout << (sum - 2 * a) << std::endl;
    }
}
