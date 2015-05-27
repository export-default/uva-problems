#include <iostream>
#include <string>
#include <cmath>

// http://uva.onlinejudge.org/external/104/10405.pdf

int lcs(const std::string &s, const std::string &t) {
    static short c[1001][1001];

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
    std::string s;
    std::string t;
    while (std::getline(std::cin,s) && std::getline(std::cin,t)) {
        std::cout << lcs(s, t) << std::endl;
    }
}
