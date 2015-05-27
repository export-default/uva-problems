#include <iostream>
#include <memory>
#include <array>
#include <cstring>

// http://uva.onlinejudge.org/external/6/674.html


long findout(const std::array<int, 5> &set, int sum) {
    std::unique_ptr<long[]> table(new long[sum + 1]);
    std::memset(table.get(), 0, sizeof(long) * (sum + 1));
    table[0] = 1;

    for (int i = 0; i < set.size(); ++i) {  // 对每个硬币
        for (int j = set[i]; j <= sum; ++j) { // 更新加上此硬币后，组成j有多少种方法。
            table[j] += table[j - set[i]];
        }
    }

    return table[sum];
}

int main() {
    std::array<int, 5> set{1, 5, 10, 25, 50};

    int sum;

    while (std::cin >> sum) {
        std::cout << findout(set, sum) << std::endl;
    }
}

