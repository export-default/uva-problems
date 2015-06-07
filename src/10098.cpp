#include <iostream>
#include <string>
#include <algorithm>

// https://uva.onlinejudge.org/external/100/p10098.pdf

bool next_permutation(std::string &p) {
    int len = p.size();
    int i;
    for (i = len - 2; i >= 0; --i) {
        if (p[i] < p[i + 1]) break;
    }

    if (i == -1) return false;

    int j;
    for (j = len - 1; j >= 0; --j) {
        if (p[j] > p[i]) break;
    }

    std::swap(p[i], p[j]);
    std::reverse(p.begin() + i + 1, p.end());
    
    return true;
}

int main() {
    int ncase;
    std::cin >> ncase;
    for (int i = 0; i < ncase; ++i) {
        std::string p;
        std::cin >> p;

        std::sort(p.begin(), p.end());
        do {
            std::cout << p << std::endl;
        } while (next_permutation(p));

        std::cout << std::endl;
    }
}

