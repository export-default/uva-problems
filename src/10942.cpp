#include <iostream>
#include <array>
#include <algorithm>
#include <iomanip>
#include <tuple>

bool leap_year(int century, int year) {
    year = century * 100 + year;
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

std::array<int, 13> days = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool day_valid(int century, int year, int month, int day) {
    if (day <= 0 && day > 31) {
        return false;
    }
    if (month != 2) {
        return day <= days[month];
    } else {
        if (leap_year(century, year)) {
            return day <= 29;
        } else {
            return day <= 28;
        }
    }
}

using date = std::tuple<int, int, int>;

int main() {
    int n_case;
    std::cin >> n_case;

    int c;
    std::array<int, 3> tmp;
    for (int i = 0; i < n_case; ++i) {
        std::cin >> c >> tmp[0] >> tmp[1] >> tmp[2];
        std::sort(std::begin(tmp), std::end(tmp));
        std::vector<date> candidates;
        do {
            if (tmp[1] <= 12 && tmp[1] >= 1 && day_valid(c, tmp[0], tmp[1], tmp[2])) {
                candidates.push_back(std::make_tuple(tmp[0], tmp[1], tmp[2]));
            }
        } while (std::next_permutation(std::begin(tmp), std::end(tmp)));
        if (!candidates.empty()) {
            date & r = *std::min_element(std::begin(candidates), std::end(candidates));
            int y, m, d;
            std::cout << std::setfill('0') << std::setw(2);
            std::cout << std::get<0>(r) << " ";
            std::cout << std::setfill('0') << std::setw(2);
            std::cout << std::get<1>(r) << " ";
            std::cout << std::setfill('0') << std::setw(2);
            std::cout << std::get<2>(r) << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }
}