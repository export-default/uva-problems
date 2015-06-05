#include <cstdio>
#include <vector>

// https://uva.onlinejudge.org/external/2/299.html

// naive method O(n^2).. see #10327 for O(n lgn) method
int inversion_count(const std::vector<int> vec) {
    int count = 0;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[i] > vec[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int ncase;
    std::scanf("%d", &ncase);
    for (int i = 0; i < ncase; ++i) {
        int n;
        std::scanf("%d", &n);

        std::vector<int> vec;
        for (int j = 0; j < n; ++j) {
            int tmp;
            std::scanf("%d", &tmp);
            vec.push_back(tmp);
        }

        std::printf("Optimal train swapping takes %d swaps.\n", inversion_count(vec));
    }
}

