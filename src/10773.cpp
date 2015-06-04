#include <iostream>
#include <cmath>
#include <iomanip>

// https://uva.onlinejudge.org/external/107/10773.html

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int d, v, u;
        std::cin >> d >> v >> u;

        if (u == 0 || v==0 || v >= u) {
            std::cout << "Case " << (i + 1) << ": " << "can't determine" << std::endl;
        } else {
            double fast = d * 1.0 / u;
            double uprime = std::sqrt(u * u - v * v);
            double shortest = d * 1.0 / uprime;
            std::cout << "Case " << (i + 1) << ": " << std::fixed << std::setprecision(3) << shortest - fast <<
            std::endl;
        }

    }
}
