#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=979


int main() {
    int n;
    std::string jolly = "Jolly";
    std::string notJolly = "Not jolly";
    while (std::cin >> n) {
        int num = 0;
        int pre = 0;
        std::vector<int> diffs;
        for (int i = 0; i < n; ++i) {
            std::cin >> num;
            if (i != 0) {
                diffs.push_back(std::abs(num - pre));
            }
            pre = num;
        }

        std::sort(diffs.begin(), diffs.end());

        bool isJolly = true;

        for (int i = 0; i < diffs.size(); ++i) {
            if (diffs[i] != (i + 1)) {
                isJolly = false;
                break;
            }
        }

        if (isJolly) {
            std::cout << jolly << std::endl;
        } else {
            std::cout << notJolly << std::endl;
        }

    }
}
