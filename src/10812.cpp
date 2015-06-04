#include <iostream>

// https://uva.onlinejudge.org/external/108/10812.html

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int s, d;
        std::cin >> s >> d;
        bool possible = (s + d) % 2 == 0 && (s >= d);
        if (possible) {
            std::cout << (s + d) / 2 <<" "<< (s - d) / 2 << std::endl;
        } else {
            std::cout << "impossible" << std::endl;
        }
    }
}
