#include <iostream>
#include <algorithm>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1012

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        std::cout << (2 * n * m) << std::endl;
    }
}