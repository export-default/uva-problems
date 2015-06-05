#include <iostream>
#include <string>

// https://uva.onlinejudge.org/external/100/p10082.pdf

const std::string kbd = R"(`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./)";

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        for (int i = 0; i < line.size(); i++)
            std::cout << (line[i] != ' ' ? kbd[kbd.find(line[i]) - 1] : ' ');
        std::cout << std::endl;
    }
}


