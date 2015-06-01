#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/5/591.html

int main() {
    int n;
    int set = 0;
    while (std::cin >> n && n != 0) {
        int tmp;
        std::vector<int> vec;
        int mid = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> tmp;
            vec.push_back(tmp);
            mid += tmp;
        }
        mid /= vec.size();

        int moves = 0;
        for (const int &i : vec) {
            if (i > mid) {
                moves += (i - mid);
            }
        }
        std::cout << "Set #" << (++set) << std::endl;
        std::cout << "The minimum number of moves is " << moves << "." << std::endl;
        std::cout << std::endl;
    }
}
