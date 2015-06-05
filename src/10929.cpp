#include <iostream>
#include <string>

// https://uva.onlinejudge.org/external/109/10929.html

int div(const std::string number, int n) {
    int remainder = 0;
    for (const char &d : number) {
        remainder += (d - '0');
        remainder %= n;
        remainder *= 10;
    }
    return remainder;
}

int main() {
    std::string line;
    while (std::cin >> line && line != "0") {
        if (div(line, 11) == 0) {
            std::cout << line << " is a multiple of 11." << std::endl;
        } else {
            std::cout << line << " is not a multiple of 11." << std::endl;
        }
    }
}
