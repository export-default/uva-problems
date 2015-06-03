#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

// https://uva.onlinejudge.org/external/103/p10305.pdf

/*
 * 给跪了。。
 * todo : fix PE
 */

std::vector<std::vector<int>> g;
std::vector<bool> visited;
int n, m;


void dfs(int i, std::list<int> &path) {
    if (!visited[i]) {
        visited[i] = true;
        for (const int &nb : g[i]) {
            dfs(nb, path);
        }
        path.push_front(i);
    }
}

int main() {
    while (std::cin >> n >> m && !(n == 0 && m == 0)) {

        g.assign((unsigned long) (n + 1), std::vector<int>());
        visited.assign((unsigned long) (n + 1), false);

        for (int i = 1; i <= m; ++i) {
            int a, b;
            std::cin >> a >> b;
            g[a].push_back(b);
        }

        std::list<int> path;
        for (int i = n; i >= 1; --i) {
            dfs(i, path);
        }

        std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
}
