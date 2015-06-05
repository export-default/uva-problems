#include <iostream>
#include <array>
#include <algorithm>

// https://uva.onlinejudge.org/external/117/p11727.pdf


int main() {
    int ncase;
    std::cin >> ncase;
    for (int i = 0; i < ncase; ++i) {
        std::array<int, 3> s;
        std::cin >> s[0] >> s[1] >> s[2];
        std::sort(std::begin(s), std::end(s));
        std::cout << "Case " << (i + 1) << ": " << s[1] << std::endl;
    }
}

