#include <iostream>

// https://uva.onlinejudge.org/external/113/11388.html

// gcd(a,b)=n, lcm(a,b)=m. take a=xn, b=yn, x coprime with y. => xy=(m/n) => x min = 1. => a = n, b = m;


int main() {
    int ncase;
    std::cin >> ncase;
    int n, m;
    for (int i = 0; i < ncase; ++i) {
        std::cin >> n >> m;
        if (m % n == 0) {
            std::cout << n << " " << m << std::endl;
        } else {
            std::cout << "-1" << std::endl;
        }
    }
}