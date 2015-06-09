#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/106/10680.html

// n>=2
std::vector<bool> prime_sieves(int n) {
    std::vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i <= n; ++i) {
        if (primes[i]) {
            int j = 2;
            while (i * j <= n) {
                primes[i * j] = false;
                j++;
            }
        }
    }
    return primes;
}

// return maximum r such that p^r <= n
int max_exponent(int p, int n) {
    int c = 0;
    while (n / p != 0) {
        n /= p;
        c++;
    }
    return c;
}

// return 2^p % 10
int _2expmod10(int p) {
    static int tmp[] = {2, 4, 8, 6};
    return tmp[(p - 1) % 4];
}

int main() {
    int n;
    auto primes = prime_sieves(1000000);

    while (std::cin >> n && n != 0) {

        int unit = 1;
        for (int i = 3; i <= n; ++i) {
            if (primes[i] && i != 5) { // skip 2 & 5
                int exp = max_exponent(i, n);
                for (int j = 0; j < exp; ++j) {
                    unit *= i;
                    unit %= 10;
                }
            }
        }

        int k2 = max_exponent(2, n);
        int k5 = max_exponent(5, n);
        if (k2 > k5) {
            unit *= _2expmod10(k2 - k5);
            unit %= 10;
        }

        std::cout << unit << std::endl;
    }
}
