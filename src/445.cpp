#include <iostream>
#include <string>

// https://uva.onlinejudge.org/external/4/445.html

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line == "") {
            std::cout << std::endl;
        } else {
            int count = 0;
            for (char ch : line) {
                if (std::isdigit(ch)) {
                    count += (ch - '0');
                } else {
                    if (count != 0) {
                        ch = ch == 'b' ? ' ' : ch;
                        std::string s(count, ch);
                        std::cout << s;
                        count = 0;
                    } else { // ch == !
                        std::cout << std::endl;
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}

