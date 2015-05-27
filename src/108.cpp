#include <iostream>
#include <cstring>
#include <limits>

// http://uva.onlinejudge.org/external/1/108.html


enum {
    max_size = 100
};


int main() {
    int input[max_size][max_size];

    int s[max_size][max_size];

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> input[i][j];
        }
    }

    // initialize s.
    std::memset(s, 0, sizeof(int) * max_size * max_size);
    s[0][0] = input[0][0];
    for (int i = 1; i < n; ++i) {
        s[0][i] = s[0][i - 1] + input[0][i];
        s[i][0] = s[i - 1][0] + input[i][0];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + input[i][j];
        }
    }

    // calc

    int max_sum = std::numeric_limits<int>::min();

    for (int r1 = 0; r1 < n; ++r1) {
        for (int r2 = r1; r2 < n; ++r2) {
            int lc = 0;
            for (int rc = 0; rc < n; ++rc) {
                int sum = s[r2][rc];
                if (lc != 0) {
                    sum -= s[r2][lc - 1];
                }
                if (r1 != 0) {
                    sum -= s[r1 - 1][rc];
                }
                if (lc != 0 && r1 != 0) {
                    sum += s[r1 - 1][lc - 1];
                }

                if (sum > max_sum) {
                    max_sum = sum;
                }

                if (sum <= 0) {
                    lc = rc + 1;
                }
            }
        }
    }

    std::cout << max_sum << std::endl;

}