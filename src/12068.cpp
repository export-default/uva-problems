#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/120/p12068.pdf

template<typename Integer>
Integer gcd(Integer a, Integer b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template<typename Integer>
Integer lcm(Integer a, Integer b) {
    return a / gcd(a, b) * b;
}


template<typename Integer>
Integer lcm(const std::vector<Integer> &vec) {
    // vec.size >= 2 && vec does not contain zero.
    Integer d = lcm(vec[0], vec[1]);
    for (int i = 2; i < vec.size(); ++i) {
        d = lcm(vec[i], d);
    }
    return d;
}

int main() {
    int ncase;
    std::cin >> ncase;
    for (int i = 0; i < ncase; ++i) {
        int num;
        std::cin >> num;

        std::vector<long> vec(num);
        for (int j = 0; j < num; ++j) {
            std::cin >> vec[j];
        }

        if (num > 1) {
            long v_lcm = lcm(vec);
            long m = v_lcm * num;
            long n = 0;
            for (int k = 0; k < vec.size(); ++k) {
                n += v_lcm / vec[k];
            }

            long mn_gcd = gcd(m, n);
            std::cout << "Case " << (i + 1) << ":" << " " << m / mn_gcd << "/" << n / mn_gcd << std::endl;
        } else { // num == 1
            std::cout << "Case " << (i + 1) << ":" << " " << vec[0] << "/" << 1 << std::endl;
        }

    }
}
