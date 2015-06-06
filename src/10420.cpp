#include <iostream>
#include <sstream>
#include <map>
#include <limits>

// https://uva.onlinejudge.org/external/104/p10420.pdf

int main() {
    int n;
    std::map<std::string, int> freqs;

    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);

        std::string country;
        std::stringstream(line) >> country;
        freqs[country] += 1;
    }

    for (const auto &pair : freqs) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

}

