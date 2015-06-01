#include <cstdio>
#include <cstring>

// https://uva.onlinejudge.org/external/106/10696.html

using namespace std;
static int cache[101];

int f91(int n) {
    if (n >= 101) {
        return n - 10;
    } else {
        if (cache[n] == -1) {
            cache[n] = f91(f91(n + 11));
        }
        return cache[n];
    }

}

int main() {
    int n;
    memset(cache, -1, sizeof(cache));
    while (scanf("%d", &n) == 1 && n != 0) {
        printf("f91(%d) = %d\n", n, f91(n));
    }
}
