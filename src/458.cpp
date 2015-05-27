#include <iostream>
#include <string>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=399

int main() {

    std::string line;
    while (std::cin >> line) {
        for (const char &ch : line) {
            std::cout << static_cast<char>(ch - 7);
        }
        std::cout << std::endl;
    }
}