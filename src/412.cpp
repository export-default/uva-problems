#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

// https://uva.onlinejudge.org/external/4/412.html

template<typename Int>
Int gcd(Int a, Int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> vec[i];
        }

        int m = 0;
        int all = 0;
        for (int j = 0; j < vec.size(); ++j) {
            for (int k = j + 1; k < vec.size(); ++k) {
                if (gcd(vec[j], vec[k]) == 1) {
                    m++;
                }
                all++;
            }
        }

        if (m == 0) {
            std::cout << "No estimate for this data set." << std::endl;
        } else {
            std::cout << std::fixed << std::setw(6) << std::sqrt(6.0 * all / m) << std::endl;
        }
    }
}
