#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iterator>

// http://uva.onlinejudge.org/external/1/116.html



void calc(const std::vector<std::vector<int>> &g, int nrows, int ncols) {
    std::vector<std::vector<int>> costs = g;
    std::vector<std::vector<int>> path = g;

    for (int c = ncols - 2; c >= 0; --c) {
        for (int r = 0; r < nrows; ++r) {
            std::vector<std::pair<int, int>> candidates;

            candidates.push_back(std::make_pair(costs[r][c + 1], r));
            candidates.push_back(std::make_pair(costs[(r - 1 + nrows) % nrows][c + 1], (r - 1 + nrows) % nrows));
            candidates.push_back(std::make_pair(costs[(r + 1) % nrows][c + 1], (r + 1) % nrows));

            std::sort(candidates.begin(), candidates.end());

            costs[r][c] = g[r][c] + candidates[0].first;
            path[r][c] = candidates[0].second;
        }
    }

    int minimum_cost = std::numeric_limits<int>::max();
    int target = 0;
    for (int i = 0; i < nrows; ++i) {
        if (minimum_cost > costs[i][0]) {
            minimum_cost = costs[i][0];
            target = i;
        }
    }
    int c = 0;
    while (c < ncols - 1) {
        std::cout << target + 1 << " ";
        target = path[target][c];
        c++;
    }
    std::cout << target + 1 << std::endl;
    std::cout << minimum_cost << std::endl;

}

int main() {
    int nrows, ncols;
    while (std::cin >> nrows >> ncols) {
        std::vector<std::vector<int>> g;
        for (int i = 0; i < nrows; ++i) {
            g.push_back(std::vector<int>());
            for (int j = 0; j < ncols; ++j) {
                int tmp;
                std::cin >> tmp;
                g[i].push_back(tmp);
            }
        }

        calc(g, nrows, ncols);
    }
}


