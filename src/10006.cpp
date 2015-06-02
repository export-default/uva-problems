#include <iostream>
#include <cmath>

// https://uva.onlinejudge.org/external/100/p10006.pdf

// todo understanding this code.
int expmod(int a, int b, int c) { // Calculate a ^ b mod c
    long long ans = 1, mult = a;
    while (b) {
        if (b & 1) {
            ans = (ans * mult) % c;
        }
        mult = (mult * mult) % c;
        b >>= 1;
    }
    return (int) ans;
}

bool prime(int n) {
    if (n == 1) {
        return false;
    }

    if (n == 2) {
        return true;
    }

    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

bool carmichael(int n) {

    if (prime(n)) {
        return false;
    } else {
        for (int i = 2; i < n; ++i) {
            if (expmod(i, n, n) != i) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        if (carmichael(n)) {
            std::cout << "The number " << n << " is a Carmichael number." << std::endl;
        } else {
            std::cout << n << " is normal." << std::endl;
        }
    }
}
