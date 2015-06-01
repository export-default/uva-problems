#include <iostream>
#include <string>

// https://uva.onlinejudge.org/external/100/p10035.pdf

int main() {
    int a, b;
    while (std::cin >> a >> b && !(a == 0 && b == 0)) {
        int count = 0;
        int c = 0;

        do {
            int i = a % 10;
            int j = b % 10;
            int sum = i + j + c;
            if (sum > 9) {
                count++;
                c = sum / 10;
            } else {
                c = 0;
            }
            a /= 10;
            b /= 10;
        } while (a != 0 || b != 0);

        if (count == 0) {
            std::cout << "No carry operation." << std::endl;
        } else if (count == 1) {
            std::cout << count << " carry operation." << std::endl;

        } else if (count > 1) {
            std::cout << count << " carry operations." << std::endl;
        }
    }
}
