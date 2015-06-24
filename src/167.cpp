#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include <iomanip>

// https://uva.onlinejudge.org/external/1/167.html

constexpr int N = 8;
int board[N][N];
int pos[N];
int maxsum = -1;

bool place(int r, int c) {
    for (int i = 0; i < r; ++i) {
        if (pos[i] == c || std::abs(r - i) == std::abs(c - pos[i])) {
            return false;
        }
    }
    return true;
}

int backtrack(int r, int acc) {
    if (r == N) {
        maxsum = std::max(maxsum, acc);
    } else {
        for (int c = 0; c < N; ++c) {
            if (place(r, c)) {
                pos[r] = c;
                backtrack(r + 1, acc + board[r][c]);
            }
        }
    }
}

int highest_score() {
    maxsum = -1;
    backtrack(0, 0);
    return maxsum;
}

int main() {
    int k;
    std::cin >> k;
    for (int icase = 0; icase < k; ++icase) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> board[i][j];
            }
        }

        std::cout << std::setw(5) << std::right << highest_score() << std::endl;
    }
}
