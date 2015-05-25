#include <iostream>
#include <string>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4460


int calc_result(const std::string &result) {
    int bonus = 0;
    int scores = 0;
    for (const auto &ch : result) {
        if (ch == 'O') {
            scores += (bonus + 1);
            bonus++;
        } else {
            bonus = 0;
        }
    }
    return scores;
}

int main() {
    int n;
    std::cin >> n;

    std::string test_result;
    for (int i = 0; i < n; ++i) {
        std::cin >> test_result;
        std::cout << calc_result(test_result) << std::endl;
    }
}