#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>

// http://uva.onlinejudge.org/external/1/111.html

std::vector<int> split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::vector<int> elems;
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::stoi(item));
    }
    return elems;
}


int score(const std::vector<int> &s, const std::vector<int> &t) {
    int c[21][21];

    for (int i = 0; i <= s.size(); ++i) {
        for (int j = 0; j <= t.size(); ++j) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (s[i - 1] == t[j - 1]) {
                c[i][j] = 1 + c[i - 1][j - 1];
            } else {
                c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
            }
        }

    }

    return c[s.size()][t.size()];
}

int main() {
    int n;
    std::cin >> n;
    std::string line;

    std::cin.get();
    std::getline(std::cin, line);
    auto tmp = split(line, ' ');

    std::vector<int> events;
    for (int i = 0; i < tmp.size(); ++i) {
        events.emplace_back(0);
    }
    for (int i = 0; i < tmp.size(); ++i) {
        events[tmp[i] - 1] = (i + 1);
    }

    while (std::getline(std::cin, line)) {
        auto rank = split(line, ' ');
        std::vector<int> order;
        for (int i = 0; i < rank.size(); ++i) {
            order.emplace_back(0);
        }
        for (int i = 0; i < rank.size(); ++i) {
            order[rank[i] - 1] = (i + 1);
        }
        std::cout << score(events, order) << std::endl;
    }
}
