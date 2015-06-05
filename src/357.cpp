#include <cstdio>
#include <array>
#include <vector>

// http://uva.onlinejudge.org/external/3/357.html


const std::array<int, 5> coins{1, 5, 10, 25, 50};

long subset_sum(int n) {
    std::vector<long> ways;
    ways.assign(n + 1, 0);
    ways[0] = 1;
    for (const auto &c : coins) {
        for (int i = c; i <= n; ++i) {
            ways[i] += ways[i - c];
        }
    }

    return ways[n];
}

int main() {
    int n;
    while (std::scanf("%d", &n) == 1) {
        auto m = subset_sum(n);
        const char *fmtstr = nullptr;
        if (m == 1) {
            fmtstr = "There is only %ld way to produce %d cents change.\n";
        } else {
            fmtstr = "There are %ld ways to produce %d cents change.\n";
        }
        std::printf(fmtstr, m, n);
    }
}