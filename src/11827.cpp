#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

// https://uva.onlinejudge.org/external/118/p11827.pdf


template<typename Integer>
Integer gcd(Integer a, Integer b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    int ncase;
    std::cin >> ncase;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < ncase; ++i) {
        std::vector<int> vec;

        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int tmp;
        while (ss >> tmp) {
            vec.push_back(tmp);
        }
        int maxgcd = -1;
        for (int k = 0; k < vec.size(); ++k) {
            for (int m = k + 1; m < vec.size(); ++m) {
                maxgcd = std::max(maxgcd, gcd(vec[k], vec[m]));
            }
        }
        std::cout << maxgcd << std::endl;
    }
}