#include <iostream>
#include <vector>
#include <algorithm>

// https://uva.onlinejudge.org/external/106/10684.html

int max_subarray_sum(const std::vector<int> vec, int n) {
    std::vector<int> table(n + 1, 0); // table[i] is the max subarray(ending in vec[i]) sum.

    for (int i = 1; i <= n; ++i) {
        if (table[i - 1] > 0) {
            table[i] = table[i - 1] + vec[i];
        } else {
            table[i] = vec[i];
        }
    }

    return *std::max_element(table.begin(), table.end());
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> vec(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> vec[i];
        }

        int s = max_subarray_sum(vec, n);

        if (s > 0) {
            std::cout << "The maximum winning streak is " << s << "." << std::endl;
        } else {
            std::cout << "Losing streak." << std::endl;
        }

    }
}
