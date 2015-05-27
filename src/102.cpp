#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <limits>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=38


int moves(int bins[3][3], const std::string colors) {
    int m = 0;
    for (int i = 0; i < 3; ++i) {
        if (colors[i] == 'B') {
            m += (bins[i][1] + bins[i][2]);
        } else if (colors[i] == 'G') {
            m += (bins[i][0] + bins[i][2]);
        } else {
            m += (bins[i][0] + bins[i][1]);
        }
    }
    return m;
}

int main() {
    int bins[3][3];
    char ch;
    while (std::cin.get(ch)) {
        std::cin.putback(ch);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cin >> bins[i][j];
            }
        }
        std::cin.get();
        std::string colors = "BCG";
        std::string mincomb = colors;
        int min = std::numeric_limits<int>::max();
        do {
            int m = moves(bins, colors);
            if (min > m) {
                min = m;
                mincomb = colors;
            } else if (min == m) {
                mincomb = std::min(mincomb, colors);
            }
        } while (std::next_permutation(colors.begin(), colors.end()));
        std::cout << mincomb << " " << min << std::endl;
    }
}