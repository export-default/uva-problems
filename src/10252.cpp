#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// https://uva.onlinejudge.org/external/102/p10252.pdf

int main() {
    std::string a, b;
    while (std::getline(std::cin, a) && std::getline(std::cin, b)) {
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        std::vector<char> common_letters;
        int i = 0;
        int j = 0;
        while (i != a.size() && j != b.size()) {
            if (a[i] < b[j]) {
                i++;
            } else if (a[i] > b[j]) {
                j++;
            } else { // equals
                common_letters.push_back(a[i]);
                i++;
                j++;
            }
        }

        std::string x(common_letters.begin(), common_letters.end());
        std::cout << x << std::endl;

    }
}


