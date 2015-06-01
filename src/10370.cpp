#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/103/p10370.pdf

int main() {
    int n_case;
    std::cin >> n_case;
    for (int i = 0; i < n_case; ++i) {
        int n;
        std::cin >> n;

        int tmp;
        int mid = 0;
        std::vector<int> vec;
        for (int j = 0; j < n; ++j) {
            std::cin >> tmp;
            vec.push_back(tmp);
            mid += tmp;
        }
        mid /= vec.size();

        int above = 0;
        for (const int &i : vec) {
            if (i > mid) {
                above++;
            }
        }

        std::cout << std::fixed;
        std::cout.precision(3);
        std::cout << (above * 100.0) / vec.size() << "%" << std::endl;
    }
}

