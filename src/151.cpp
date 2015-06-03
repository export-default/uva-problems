#include <iostream>
#include <vector>

// http://uva.onlinejudge.org/external/1/151.html


int last(int n, int m) {
    constexpr int IN = 0;
    constexpr int OUT = 1;

    std::vector<int> vec;
    vec.assign(n + 1, IN);
    vec[1] = OUT;
    int nout = 1;
    int i = 1;
    while (nout != n) {
        int count = 0;
        while (count != m) {
            if (i == n) {
                i = 1;
            } else {
                i++;
            }
            if (vec[i] == IN) {
                count++;
            }
        }
        vec[i] = OUT;
        nout++;
    }

    return i;
}

int findout(int n) {
    int i = 1;
    while (last(n, i) != 13) {
        ++i;
    }
    return i;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::cout << findout(n) << std::endl;
    }
}