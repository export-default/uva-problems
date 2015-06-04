#include <cstdio>
#include <cmath>

// https://uva.onlinejudge.org/external/2/294.html
// http://en.wikipedia.org/wiki/Divisor_function  divisor number and prime factor have a close relationship.

int divisors_number(int n) {
    int divisor_count = 1;
    int factor_count = 0;

    while (n % 2 == 0) {
        factor_count++;
        n /= 2;
    }
    divisor_count *= (factor_count + 1);
    for (int k = 3; k <= std::sqrt(n); k += 2) {
        factor_count = 0;
        while (n % k == 0) {
            factor_count++;
            n /= k;
        }
        divisor_count *= (factor_count + 1);
    }

    if (n > 2) { // n is a prime
        divisor_count *= 2;
    }
    return divisor_count;
}

int main() {
    int n;
    std::scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int L, U;
        std::scanf("%d%d", &L, &U);

        int divisor_max_count = -1;
        int target = -1;

        for (int j = L; j <= U; ++j) {
            int count = divisors_number(j);
            if (divisor_max_count < count) {
                divisor_max_count = count;
                target = j;
            }
        }

        std::printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, target, divisor_max_count);

    }
}
