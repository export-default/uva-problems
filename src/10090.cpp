#include <iostream>
#include <utility>
#include <tuple>
#include <limits>
#include <cmath>
#include <cstdint>

// https://uva.onlinejudge.org/external/100/p10090.pdf
// linear diophantine equation: n1*x + n2*y = n
// and c1*x + c2*y minimized.

template<typename Integer>
std::tuple<Integer, Integer, Integer> extended_euclid(Integer a, Integer b) {
    if (b == 0) {
        return std::make_tuple(a, static_cast<Integer>(1), static_cast<Integer>(0));
    } else {
        Integer dprime, xprime, yprime;
        std::tie(dprime, xprime, yprime) = extended_euclid(b, a % b);
        return std::make_tuple(dprime, yprime, xprime - (a / b) * yprime);
    }
}

int main() {
    int64_t n;
    int64_t c1, n1, c2, n2;

    while (std::cin >> n && n != 0) {
        std::cin >> c1 >> n1 >> c2 >> n2;

        int64_t d, xp, yp;
        std::tie(d, xp, yp) = extended_euclid(n1, n2);

        if (n % d != 0) {
            std::cout << "failed" << std::endl;
        } else {
            int64_t x_0 = n / d * xp;
            int64_t y_0 = n / d * yp;
            int64_t dx = n2 / d;
            int64_t dy = n1 / d;
            int64_t k_max = (int64_t) std::floor(1.0 * n / n1 * yp);
            int64_t k_min = (int64_t) std::ceil(-1.0 * n / n2 * xp);

            if (k_min > k_max) {
                std::cout << "failed" << std::endl;
            } else {
                int64_t x_opt, y_opt;
                int64_t x_1 = x_0 + k_min * dx;
                int64_t y_1 = y_0 - k_min * dy;

                int64_t x_2 = x_0 + k_max * dx;
                int64_t y_2 = y_0 - k_max * dy;

                if (c1 * x_1 + c2 * y_1 < c1 * x_2 + c2 * y_2) {
                    x_opt = x_1;
                    y_opt = y_1;
                }else{
                    x_opt = x_2;
                    y_opt = y_2;
                }
                std::cout << x_opt << " " << y_opt << std::endl;
            }
        }

    }

}
