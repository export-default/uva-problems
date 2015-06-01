#include <iostream>

// https://uva.onlinejudge.org/external/107/10783.html

int main() {
    int n_case;
    std::cin >> n_case;
    for (int i = 0; i < n_case; ++i) {
        int a, b;
        std::cin >> a >> b;

        bool odd_a = (a % 2 != 0);
        bool odd_b = (b % 2 != 0);

        int sum = 0;
        if (odd_a && odd_b) {
            int n = (b - a + 1) / 2 + 1;
            sum = n * (a + b) / 2;
        } else if (!odd_a && !odd_b) {
            int n = (b - a + 1) / 2;
            sum = n * (a + b) / 2;
        } else if (odd_a && !odd_b) {
            int n = (b - a + 1) / 2;
            sum = n * (a + b - 1) / 2;
        } else {
            int n = (b - a + 1) / 2;
            sum = n * (a + b + 1) / 2;
        }

        std::cout << "Case " << (i + 1) << ": " << sum << std::endl;
    }
}
