#include <iostream>
#include <string>
#include <cmath>

// https://uva.onlinejudge.org/external/5/575.html


int todecimal(const std::string &sb_number) {
    int n = 0;
    for (int i = 0; i < sb_number.size(); ++i) {
        int num = sb_number[i] - '0';
        if (num != 0) {
            n += (num) * (std::pow(2, sb_number.size() - i) - 1);
            if (num == 2) {
                break;
            }
        }
    }
    return n;
}

int main() {
    std::string sb_number;
    while (std::cin >> sb_number && sb_number != "0") {
        std::cout << todecimal(sb_number) << std::endl;
    }
}
