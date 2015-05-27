#include <iostream>
#include <cmath>

// http://uva.onlinejudge.org/external/1/113.html


int main() {
    double n, p;
    while (std::cin >> n >> p) {
        std::cout.precision(0);
        std::cout << std::fixed;
        std::cout << std::pow(p, 1 / n) << std::endl;
    }
}

