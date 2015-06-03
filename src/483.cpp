#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// https://uva.onlinejudge.org/external/4/483.html


int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stack<char> s;
        for (int i = 0; i < line.size(); ++i) {
            if (!std::isblank(line[i])) {
                s.push(line[i]);
            } else {
                while (!s.empty()) {
                    std::cout << s.top();
                    s.pop();
                }
                std::cout << " ";
            }
        }
        while (!s.empty()) {
            std::cout << s.top();
            s.pop();
        }
        std::cout << std::endl;
    }
}
