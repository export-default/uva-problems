#include <iostream>

// https://uva.onlinejudge.org/external/111/11150.html

int main() {
    int n = 0;
    while (std::cin >> n) {
        int m = 0, s = 0;
        while (!(n == 0 && m < 3)) {
            s += n;
            m += n;
            n = m / 3;
            m = m % 3;
        }
        if (m == 2) {
            s += 1;
        }
        std::cout << s << std::endl;
    }
}
