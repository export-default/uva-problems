#include <iostream>
#include <string>

// http://uva.onlinejudge.org/external/101/p10192.pdf


int lcs(const std::string &s, const std::string &t) {
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

    std::string s, t;
    int count = 1;
    while (std::getline(std::cin, s)) {
        if (s == "#") {
            break;
        }
        std::getline(std::cin, t);
        std::cout << "Case #" << count << ": you can visit at most " << lcs(s, t) << " cities." << std::endl;
        count++;
    }
}
