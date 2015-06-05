#include <iostream>
#include <string>

// https://uva.onlinejudge.org/external/4/488.html

void print(int a, int f) {
    for (int i = 0; i < f; ++i) {

        for (int k = 1; k <= a; ++k) {
            std::string s(k, '0' + k);
            std::cout << s << std::endl;
        }

        for (int k = a - 1; k >= 1; --k) {
            std::string s(k, '0' + k);
            std::cout << s << std::endl;
        }

        if (i != f - 1) {
            std::cout << std::endl;
        }
    }
}

int main() {
    int ncase;
    std::cin >> ncase;
    for (int i = 0; i < ncase; ++i) {
        int a, f;
        std::cin >> a >> f;
        print(a, f);
        if (i != ncase - 1) {
            std::cout << std::endl;
        }
    }
}
