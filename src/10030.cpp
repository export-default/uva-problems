#include <iostream>

// https://uva.onlinejudge.org/external/103/p10300.pdf

int main() {
    int n_case;
    std::cin >> n_case;
    for (int i = 0; i < n_case; ++i) {
        int f;
        std::cin >> f;

        long sum = 0;
        long size, n_animals, quality;
        for (int j = 0; j < f; ++j) {
            std::cin >> size >> n_animals >> quality;
            sum += (size * quality);
        }
        std::cout << sum << std::endl;
    }
}
