#include <iostream>
#include <cmath>

// https://uva.onlinejudge.org/external/106/10673.html

int main() {
    int ncase;
    std::cin >> ncase;
    for (int i = 0; i < ncase; ++i) {
        int x, k;
        std::cin >> x >> k;

        int n = x / k;
        int m = x % k;

        if (m == 0) {
            std::cout << "1 " << k - 1 << std::endl;
        } else {
            std::cout << k - m << " " << m << std::endl;
        }
    }
}
