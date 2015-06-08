#include <iostream>
#include <tuple>

// https://uva.onlinejudge.org/external/101/p10104.pdf


// return <d,x,y>. d = gcd(a,b) & d = ax + by
template<typename Integer>
std::tuple<Integer, Integer,Integer> extended_euclid(Integer a, Integer b) {
    if (b == 0) {
        return std::make_tuple(a, static_cast<Integer>(1), static_cast<Integer>(0));
    } else {
        Integer dprime, xprime, yprime;
        std::tie(dprime, xprime, yprime) = extended_euclid(b, a % b);
        return std::make_tuple(dprime, yprime, xprime - (a / b) * yprime);
    }
}

int main() {
    int a, b;
    while (std::cin >> a >> b) {
        int d, x, y;
        std::tie(d, x, y) = extended_euclid(a, b);
        std::cout << x << " " << y << " " << d << std::endl;
    }
}