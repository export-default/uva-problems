#include <iostream>
#include <algorithm>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=208

std::string out[] = {"``", "''"};

int main() {
    std::string line;
    bool first = true;
    char ch;
    while (std::cin.get(ch)) {
        if (ch == '\"') {
            std::cout << out[first ? 0 : 1];
            first = !first;
        } else {
            std::cout << ch;
        }
    }
}