#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/106/10608.html

int dfs(const std::vector<std::vector<int>> &g, std::vector<bool> & visited, int k) {
    if (visited[k]) {
        return 0;
    } else {
        visited[k] = true;
        int size = 1;
        for (int nb : g[k]) {
            size += dfs(g, visited, nb);
        }
        return size;
    }
}

int main() {
    int ncase;
    std::cin >> ncase;
    for (int i = 0; i < ncase; ++i) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> g(n + 1);
        std::vector<bool> visited(n + 1, false);
        for (int j = 0; j < m; ++j) {
            int a, b;
            std::cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int maxsize = -1;
        for (int k = 1; k <= n; ++k) {
            if (!visited[k]) {
                int size = dfs(g, visited, k);
                maxsize = std::max(size, maxsize);
            }
        }

        std::cout << maxsize << std::endl;
    }
}
