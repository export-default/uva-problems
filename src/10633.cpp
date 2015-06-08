#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

// https://uva.onlinejudge.org/external/106/10633.html
// M = (N - N%10)/10  => 10(N-M) = 9N + N %10 = 10X..

int main() {
    uint64_t x;
    while (std::cin >> x && x != 0L) {
        std::vector<uint64_t> solutions;
        for (unsigned int i = 0; i < 10; ++i) {
            uint64_t n = (10 * x - i) / 9;
            if ((10 * x - i) % 9 == 0 && n % 10 == i) {
                solutions.push_back(n);
            }
        }
        std::sort(solutions.begin(), solutions.end());
        std::cout << solutions[0];
        for (int j = 1; j < solutions.size(); ++j) {
            std::cout << " " << solutions[j];
        }
        std::cout << std::endl;
    }
}
