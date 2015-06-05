#include <iostream>
#include <string>
#include <stack>

// https://uva.onlinejudge.org/external/6/673.html
// input string will have space

bool correct(const std::string &line) {
    std::stack<char> s;
    for (char ch : line) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == ']') {
            if (s.empty()) {
                return false;
            } else {
                if ((ch == ')' && s.top() == '(') || (ch == ']' && s.top() == '[')) {
                    s.pop();
                } else {
                    return false;
                }
            }

        }
    }
    return s.empty();
}

int main() {
    int ncase;
    std::cin >> ncase;
    std::cin.ignore(10, '\n');
    for (int i = 0; i < ncase; ++i) {
        std::string line;
        std::getline(std::cin, line);
        if (correct(line)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}

