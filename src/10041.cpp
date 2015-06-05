#include <iostream>
#include <vector>
#include <algorithm>

// https://uva.onlinejudge.org/external/100/p10041.pdf
// median. The geometric median of a discrete set of sample points in a Euclidean space
// is the point minimizing the sum of distances to the sample points.

int distance(const std::vector<int> vec, int m) {
    int sum = 0;
    std::for_each(std::begin(vec), std::end(vec), [&sum,m](const int &a) {
        sum += std::abs(m - a);
    });
    return sum;
}

int main() {
    int ncase;
    std::cin >> ncase;
    for (int i = 0; i < ncase; ++i) {
        int n;
        std::cin >> n;

        std::vector<int> vec;
        for (int j = 0; j < n; ++j) {
            int tmp;
            std::cin >> tmp;
            vec.push_back(tmp);
        }

        std::sort(std::begin(vec), std::end(vec));

        int minimum_distance;
        if (vec.size() % 2 == 0) {
            minimum_distance = std::min(distance(vec, vec[vec.size() / 2]), distance(vec, vec[vec.size() / 2 - 1]));
        } else {
            minimum_distance = distance(vec, vec[vec.size() / 2]);
        }
        std::cout << minimum_distance << std::endl;
    }
}
