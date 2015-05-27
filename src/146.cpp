#include <iostream>
#include <string>
#include <algorithm>

// http://uva.onlinejudge.org/external/1/146.html

int main() {
    std::string line;
    while (std::cin >> line && line != "#") {
        int len = (int) line.size();
        bool has_next = false;
        int i = 0;
        int j = 0;

        for (int k = len - 1; k >= 1; --k) {
            if (line[k] > line[k - 1]) {
                i = k - 1;
                has_next = true;
                break;
            }
        }

        if (!has_next) {
            std::cout << "No Successor" << std::endl;
        } else {
            for (int k = len - 1; k >= 0; --k) {
                if (line[k] > line[i]) {
                    j = k;
                    break;
                }
            }

            std::swap(line[i], line[j]);
            std::reverse(line.begin() + i + 1, line.end());
            std::cout << line << std::endl;
        }

    }
}
