#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4400


void call(const std::vector<std::string> &names, int pos) {
    pos -= 1; // 0-indexed;

    if (names[pos] != "?") {
        std::cout << names[pos] << std::endl;
    } else {
        int distance = 1;
        bool left = false;
        bool right = false;
        int len = names.size();
        std::string left_neighbor;
        std::string right_neighbor;
        while (true) {
            if (pos + distance < len && names[pos + distance] != "?") {
                right_neighbor = names[pos + distance];
                right = true;
            }

            if (pos - distance > -1 && names[pos - distance] != "?") {
                left_neighbor = names[pos - distance];
                left = true;
            }

            if (right || left) {
                break;
            } else {
                distance++;
            }
        }

        if (right && left) {
            std::cout << "middle of " << left_neighbor << " and " << right_neighbor << std::endl;
        } else if (right) {
            for (int i = 0; i < distance; ++i) {
                std::cout << "left of ";
            }
            std::cout << right_neighbor << std::endl;
        } else if (left) {
            for (int i = 0; i < distance; ++i) {
                std::cout << "right of ";
            }
            std::cout << left_neighbor << std::endl;
        }
    }
}

int main() {
    int n_names;
    std::cin >> n_names;
    std::vector<std::string> names;
    for (int i = 0; i < n_names; ++i) {
        std::string name;
        std::cin >> name;
        names.push_back(name);
    }

    int n_queries;
    std::cin >> n_queries;

    for (int j = 0; j < n_queries; ++j) {
        int pos;
        std::cin >> pos;
        call(names, pos);
    }
}