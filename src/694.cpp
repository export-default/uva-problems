#include <cstdio>

// https://uva.onlinejudge.org/external/6/694.html

int count(long A, long L) {
    int c = 1;
    while (A != 1) {
        if (A % 2 == 0) {
            A /= 2;
        } else {
            A = 3 * A + 1;
            if (A > L) {
                break;
            }
        }
        c++;
    }
    return c;
}

int main() {
    long A, L;
    int ncase = 1;
    while (std::scanf("%ld%ld", &A, &L) == 2 && !(A < 0 && L < 0)) {
        std::printf("Case %d: A = %ld, limit = %ld, number of terms = %d\n", ncase++, A, L, count(A, L));
    }
}

