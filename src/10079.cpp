#include <iostream>

// https://uva.onlinejudge.org/external/100/p10079.pdf

int main() {
    long n;
    while (std::cin >> n && n >= 0) {
        std::cout << (n * n + n) / 2 + 1 << std::endl;
    }
}