#include <iostream>

// https://uva.onlinejudge.org/external/114/11417.html

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        int g = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                g += gcd(i, j);
            }
        }
        std::cout << g << std::endl;
    }
}
