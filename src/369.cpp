#include <cstdio>
#include <vector>
#include <cmath>

// https://uva.onlinejudge.org/external/3/369.html


long combination(int n, int m) {
    long numerator = 1;
    long denominator = 1;

    for (int i = 2; i <= n; ++i) {

        if (denominator % i == 0) {
            denominator /= i;
        } else {
            numerator *= i;
        }

        if (i <= m) {
            if (numerator % i == 0) {
                numerator /= i;
            } else {
                denominator *= i;
            }
        }

        if (i <= n - m) {
            if (numerator % i == 0) {
                numerator /= i;
            } else {
                denominator *= i;
            }
        }

    }

    return numerator / denominator;
}

int main() {
    int n, m;
    while (std::scanf("%d%d", &n, &m) == 2 && !(n == 0 && m == 0)) {
        std::printf("%d things taken %d at a time is %ld exactly.\n", n, m, combination(n, m));
    }
}