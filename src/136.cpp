#include <iostream>
#include <vector>
#include <cmath>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=72



bool is_ugly(int n) {
    for (const auto &i : {2, 3, 5}) {
        while (n % i == 0)
            n /= i;
    }
    return n == 1;
}
//859963392
//int main() {
//    int count = 0;
//    int start = 1;
//    while (count < 1500) {
//        if (is_ugly(start)) {
//            count++;
//        }
//        start++;
//    }
//    start -= 1;
//    std::cout << start << std::endl;
//}

int main() {
    std::cout << "The 1500'th ugly number is " << 859963392 << "." << std::endl;
}