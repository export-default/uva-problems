#include <cstdio>
#include <array>
#include <vector>

// https://uva.onlinejudge.org/external/1/147.html

const std::array<int, 11> coins{5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long subset_sums(int n) {
    std::vector<long> ways(n + 1, 0);
    ways[0] = 1;
    for (const int &c : coins) {
        for (int i = c; i <= n; ++i) {
            ways[i] += ways[i - c];
        }
    }
    return ways[n];
}

int main() {
    int a, b;
    while (std::scanf("%d.%d", &a, &b) == 2 && !(a == 0 && b == 0)) {
        std::printf("%3d.%02d%17ld\n", a, b, subset_sums(a * 100 + b));
    }
}

