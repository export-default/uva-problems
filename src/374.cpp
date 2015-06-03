#include <iostream>
#include <cstdint>

// https://uva.onlinejudge.org/external/3/374.html

uint32_t expmod(uint32_t b, uint32_t p, uint32_t m) {
    long long ans = 1;
    long long mult = b;
    while (p) {
        if (p & 1) {
            ans = (ans * mult) % m;
        }
        mult = (mult * mult) % m;
        p >>= 1;
    }
    return (uint32_t) ans;
}

int main() {
    uint32_t b, p, m;
    while (std::cin >> b >> p >> m) {
        std::cout << expmod(b, p, m) << std::endl;
    }
}
