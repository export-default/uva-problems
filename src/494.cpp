#include <iostream>
#include <string>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=435


int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        int count = 0;
        bool pre_letter = false;
        for (int i = 0; i < line.size(); ++i) {
            if (isalpha(line[i])) {
                pre_letter = true;
            } else {
                if (pre_letter) {
                    count += 1;
                }
                pre_letter = false;
            }
        }
        std::cout << count << std::endl;
    }
}