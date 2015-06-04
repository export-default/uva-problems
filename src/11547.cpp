#include <iostream>
#include <cmath>

// https://uva.onlinejudge.org/external/115/p11547.pdf

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        int r = ((315 * n + 36962) / 10) % 10;
        std::cout << std::abs(r) << std::endl;
    }
}
