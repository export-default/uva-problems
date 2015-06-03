#include <cstdio>
#include <cmath>

// https://uva.onlinejudge.org/external/1/138.html

using namespace std;

int main() {
    double n = 2;
    double x;
    int count = 0;
    while (count < 10) {
        x = sqrt(n * (n + 1) / 2);
        if (x == (int)x) {
            count++;
            printf("%10d%10d\n", (int) x, (int) n);
        }
        n++;
    }
}

