#include <iostream>

// https://uva.onlinejudge.org/external/108/10892.html

// n = product of (p_i ^ n_i) (prime factorization) lcm cardinality = product of (n_i +1)..
// over counting http://www.algorithmist.com/index.php/UVa_10892


int lcm_cadinality(int n) {
    int card = 1;
    int i = 2;

    while (n != 1) {
        int c = 0;
        while (n % i == 0) {
            c++;
            n /= i;
        }
        card *= (2 * c + 1);
        i++;
    }
    return (card + 1) / 2;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::cout << n << " " << lcm_cadinality(n) << std::endl;
    }
}
