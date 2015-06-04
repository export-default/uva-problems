#include <iostream>
#include <string>
#include <cmath>

// https://uva.onlinejudge.org/external/109/10924.html

bool prime(int n) {
    if (n <= 1) {
        return true; // in this problem
    }
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string words;
    while (std::cin >> words) {
        int sum = 0;
        for (const auto &ch: words) {
            if (std::isupper(ch)) {
                sum += ch - 'A' + 27;
            } else {
                sum += ch - 'a' + 1;
            }
        }
        if (prime(sum)) {
            std::cout << "It is a prime word." << std::endl;
        } else {
            std::cout << "It is not a prime word." << std::endl;
        }
    }
}