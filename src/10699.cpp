#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/106/10699.html

// n>=2
std::vector<bool> prime_seives(int n) {
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

int main() {
    int n;
    auto primes = prime_seives(1000000);
    while (std::cin >> n && n != 0) {
        int c = 0;
        for (int i = 2; i <= n; ++i) {
            if (primes[i] && n % i == 0) {
                c++;
            }
        }
        std::cout << n << " : " << c << std::endl;
    }
}
