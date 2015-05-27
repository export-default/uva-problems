#include <iostream>
#include <vector>
// http://uva.onlinejudge.org/external/100/p10066.pdf


int lcs(const std::vector<int> &s, const std::vector<int> &t) {
    int c[101][101];

    for (int i = 0; i <= s.size(); ++i) {
        for (int j = 0; j <= t.size(); ++j) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (s[i - 1] == t[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    return c[s.size()][t.size()];
}

int main() {
    int m, n;
    int count = 1;
    while (std::cin >> m >> n && !(m == 0 && n == 0)) {
        std::vector<int> s;
        std::vector<int> t;
        int tmp;

        for (int i = 0; i < m; ++i) {
            std::cin >> tmp;
            s.push_back(tmp);
        }

        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            t.push_back(tmp);
        }

        std::cout << "Twin Towers #" << count << std::endl;
        std::cout << "Number of Tiles : " << lcs(s, t) << std::endl;
        std::cout << std::endl;

        count++;
    }
}
