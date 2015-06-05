#include <iostream>
#include <iomanip>

// https://uva.onlinejudge.org/external/5/568.html
// factorial's prime decomposition http://en.wikipedia.org/wiki/De_Polignac's_formula
// http://www.quora.com/What-is-the-first-non-zero-digit-in-50-factorial-50
// http://math.stackexchange.com/questions/848501/to-find-the-right-most-non-zero-digit

// 阶乘的素因之分解！

// compute prime k's component in n!'s prime decomposition
int k_component(int n, int k) {
    int c = 0;
    int d;
    int base = k;
    while ((d = n / k) != 0) {
        c += d;
        k *= base;
    }
    return c;
}

// return 2^p % 10
int _2expmod10(int p) {
    static int tmp[] = {2, 4, 8, 6};
    return tmp[(p - 1) % 4];
}

int last_nonzero_digit_of_factorial_1(int n) {
    int k2 = k_component(n, 2);
    int k5 = k_component(n, 5);
    int last = 1;

    for (int i = 1; i <= n; ++i) {
        int num = i;
        while (num % 2 == 0)
            num /= 2;
        while (num % 5 == 0)
            num /= 5;
        last *= num;
        last %= 10;
    }

    if (k2 > k5) {
        last = last * _2expmod10(k2 - k5);
    }

    return last % 10;
}

// http://quantomania.blogspot.in/2011/08/last-non-zero-digit-of-factorial.html todo WHY?
int last_nonzero_digit_of_factorial_2(int n) {
    static int cache[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
    if (n < 10) {
        return cache[n];
    } else if ((n / 10) % 2 == 0) {
        int d = 6 * last_nonzero_digit_of_factorial_2(n / 5) * last_nonzero_digit_of_factorial_2(n % 10);
        return d % 10;
    } else {
        int d = 4 * last_nonzero_digit_of_factorial_2(n / 5) * last_nonzero_digit_of_factorial_2(n % 10);
        return d % 10;
    }
}

int main() {
    int n;
    while (std::cin >> n) {
        std::cout << std::setw(5) << std::right << n << " -> " << last_nonzero_digit_of_factorial_2(n) << std::endl;
    }
}

