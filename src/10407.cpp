#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

// https://uva.onlinejudge.org/external/104/p10407.pdf
// http://www.algorithmist.com/index.php/UVa_10407

template<typename Integer>
Integer gcd(Integer a, Integer b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template<typename Integer>
Integer gcd(const std::vector<Integer> &vec) {
    // vec.size >= 2 && vec does not contain zero.
    Integer d = gcd(vec[0], vec[1]);
    for (int i = 2; i < vec.size(); ++i) {
        d = gcd(vec[i], d);
    }
    return d;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line) && line != "0") {
        std::vector<int> diffs;
        std::stringstream ss(line);
        int pre, d;
        ss >> pre;
        while (ss >> d && d != 0) {
            if (d - pre != 0) {
                diffs.push_back(std::abs(d - pre));
            }
            pre = d;
        }
        if (diffs.size() == 1) {
            std::cout << diffs[0] << std::endl;
        } else {
            std::cout << gcd(diffs) << std::endl;
        }
    }
}
