#include <iostream>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2113

int main() {
    int n_case;
    std::cin >> n_case;
    int a, b;
    for (int i = 0; i < n_case; ++i) {
        std::cin >> a >> b;
        if (a - b == 0) {
            std::cout << "=" << std::endl;
        } else if (a - b < 0) {
            std::cout << "<" << std::endl;
        } else {
            std::cout << ">" << std::endl;
        }
    }
}