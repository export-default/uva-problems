#include <iostream>
#include <algorithm>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=996

int main() {
    long n, m;
    while (std::cin >> n >> m) {
        std::cout << std::max(n,m) - std::min(n,m) << std::endl;
    }
}