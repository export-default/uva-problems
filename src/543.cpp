#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/5/543.html

// n >= 2
std::vector<bool> prime_seives(int n) {
    std::vector<bool> primes;
    primes.assign(n + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (primes[i] == true) {
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
    auto primes = prime_seives(1000000);
    int n;
    while (std::cin >> n && n != 0) {
        int a, b;
        bool hasSolution = false;
        for (a = 2; a < n; ++a) {
            b = n - a;
            if (primes[a] && primes[b]) {
                hasSolution = true;
                break;
            }
        }

        if (hasSolution) {
            std::cout << n << " = " << a << " + " << b << std::endl;
        } else {
            std::cout << "Goldbach's conjecture is wrong." << std::endl;
        }
    }
}

