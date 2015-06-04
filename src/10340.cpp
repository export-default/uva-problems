#include <iostream>
#include <string>

// https://uva.onlinejudge.org/external/103/p10340.pdf

bool is_subsequence(std::string s, std::string t) {
    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == s.size();
}

int main() {
    std::string s, t;
    while (std::cin >> s >> t) {
        if (is_subsequence(s, t)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}