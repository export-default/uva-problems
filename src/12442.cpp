#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/124/p12442.pdf

/*
 * sum缓存：如果节点在被按顺序访问之前被访问过（有过缓存），则该节点一定不是答案（不是最小的节点或不是最多的长度）。
 */

std::vector<int> graph, sum;
std::vector<bool> vis;

int dfs(int u) {
    vis[u] = true;
    int tot = 0;
    if (graph[u] != -1 && !vis[graph[u]])
        tot += 1 + dfs(graph[u]);
    vis[u] = false;
    return sum[u] = tot;
}

int main() {
    int n_case;
    std::cin >> n_case;
    for (int i = 1; i <= n_case; ++i) {
        int n;
        std::cin >> n;
        graph.assign(n, -1);
        sum.assign(n, -1);
        vis.assign(n, false);
        for (int j = 0; j < n; ++j) {
            int u, v;
            std::cin >> u >> v;
            graph[u - 1] = v - 1;
        }

        int ans = 0, best_len = 0;
        for (int i = 0; i < n; i++) {
            if (sum[i] == -1) dfs(i);
            if (sum[i] > best_len) {
                best_len = sum[i];
                ans = i;
            }
        }

        std::cout << "Case " << i << ": " << (ans + 1) << std::endl;
    }
}
