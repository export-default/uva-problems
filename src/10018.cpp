#include <iostream>

// https://uva.onlinejudge.org/external/100/p10018.pdf

long reverse(long x) {
    long rev = 0;
    while (x != 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        long a;
        std::cin >> a;

        int count = 0;
        long rev = reverse(a);
        do {
            a += rev;
            count++;
            rev = reverse(a);
        } while (rev != a);

        std::cout << count << " " << a << std::endl;

    }
}
