#include <iostream>
#include <string>
#include <unordered_map>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4461

std::unordered_map<char, double> m = {
        {'C', 12.01},
        {'H', 1.008},
        {'O', 16.00},
        {'N', 14.01}
};


double molar_mass(const std::string &formula) {
    char ch;
    double mass = 0;
    char pre = 0;
    int pre_cout = 0;
    for (int i = 0; i < formula.size(); ++i) {
        ch = formula[i];

        if (std::isalpha(ch)) {
            pre_cout = pre_cout == 0 ? 1 : pre_cout;
            mass += m[pre] * pre_cout;
            pre_cout = 0;
            pre = ch;
        } else {
            pre_cout *= 10;
            pre_cout += (ch - '0');
        }

    }
    pre_cout = pre_cout == 0 ? 1 : pre_cout;
    mass += m[pre] * pre_cout;
    return mass;
}

int main() {
    int n_case;
    std::cin >> n_case;

    std::string formula;
    std::cout.precision(3);
    std::cout << std::fixed;
    for (int i = 0; i < n_case; ++i) {
        std::cin >> formula;
        std::cout << molar_mass(formula) << std::endl;
    }
}