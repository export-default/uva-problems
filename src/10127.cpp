#include <iostream>

// https://uva.onlinejudge.org/external/101/p10127.pdf

// 除法的性质: 135874562154683215478953155468633 不用bigint，如何求余数(除数在int范围内)?

int findout(int a) {
    int x = 0;
    int n = 0;
    do {
        x++;
        n = n * 10 + 1;
        n = n % a;
    } while (n != 0);
    return x;
}

int main() {
    int a;
    while (std::cin >> a) {
        std::cout << findout(a) << std::endl;
    }
}
