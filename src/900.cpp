#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/9/p900.pdf
// 根据第一块砖如何放置，递推

int main() {
    int n;
    std::vector<long> counts(51);
    counts[1] = 1;
    counts[2] = 2;
    for (int i = 3; i <= 50; ++i) {
        counts[i] = counts[i - 1] + counts[i - 2];
    }
    while (std::cin >> n && n != 0) {
        std::cout << counts[n] << std::endl;
    }
}
