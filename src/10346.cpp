#include <iostream>

// https://uva.onlinejudge.org/external/103/p10346.pdf
// similar with #11150

int main() {
    int n, k;
    while (std::cin >> n >> k) {
        int butts = 0;
        int all = 0;
        while (!(n == 0 && butts < k)) {
            all += n;
            butts += n;
            n = butts / k;
            butts %= k;
        }
        std::cout << all << std::endl;
    }
}
