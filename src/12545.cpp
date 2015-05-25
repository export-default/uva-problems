#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3990

// s[i]=1 & t[i]=0 +1
// s[i]=0 & t[i]=1 -1
// s[i]=? & t[i]=0 -2
// s[i]=? & t[i]=1 +2
int transform_distance(const std::string &s, const std::string &t) {
    int plus_1 = 0;
    int plus_2 = 0;
    int minus_1 = 0;
    int minus_2 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            if (t[i] == '0') {
                minus_2++;
            } else {
                plus_2++;
            }
        } else if (s[i] == '1' && t[i] == '0') {
            plus_1++;
        } else if (s[i] == '0' && t[i] == '1') {
            minus_1++;
        }
    }

    if (plus_1 == minus_1) {
        // swap 0 <-> 1
        return plus_2 + minus_2 + plus_1;
    } else if (plus_1 > minus_1 && (plus_1 - minus_1) <= plus_2) {
        // swap 1 <-> ?(+2)
        return plus_2 + minus_2 + plus_1;
    } else if (plus_1 < minus_1) {
        // swap 0 <-> 1, then change 0 -> 1
        return plus_2 + minus_2 + minus_1;
    } else {
        return -1;
    }
}

int main() {
    int n_case;
    std::string s, t;
    std::cin >> n_case;
    for (int i = 0; i < n_case; ++i) {
        std::cin >> s >> t;
        std::cout << "Case " << (i + 1) << ": " << transform_distance(s, t) << std::endl;
    }
}


