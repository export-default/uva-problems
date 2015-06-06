#include <iostream>
#include <vector>
#include <algorithm>

// https://uva.onlinejudge.org/external/114/p11462.pdf

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> vec[i];
        }
        std::sort(std::begin(vec), std::end(vec));
        std::cout << vec[0];
        for (int j = 1; j < vec.size(); ++j) {
            std::cout << " " << vec[j];
        }
        std::cout << std::endl;
    }
}

