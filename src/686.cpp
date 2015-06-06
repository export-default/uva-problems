#include <iostream>
#include <vector>

// n >= 2
std::vector<bool> prime_seives(int n) {
    std::vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
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
    std::vector<bool> primes = prime_seives(32768);
    while (std::cin >> n && n != 0) {
        int pairs = 0;
        for (int i = 2; i <= n / 2; ++i) {
            if (primes[i] && primes[n - i]) {
                pairs++;
            }
        }
        std::cout << pairs << std::endl;
    }
}

