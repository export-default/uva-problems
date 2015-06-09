#include <iostream>
#include <vector>
#include <map>

// https://uva.onlinejudge.org/external/115/p11503.pdf

struct disjoint_set {
    disjoint_set(int n) : handle(n + 1) {
        for (int i = 1; i <= n; ++i) {
            handle[i].p = i;
        }
    }

    int find(int x) {
        if (handle[x].p != x) { // not root
            handle[x].p = find(handle[x].p); // path compression
        }
        return handle[x].p;
    }

    // keep the set size in root node.
    int link(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) { // link by rank
            if (handle[rx].rank > handle[ry].rank) {
                handle[ry].p = rx;
                handle[rx].count += handle[ry].count;
                return handle[rx].count;
            } else {
                handle[rx].p = ry;
                handle[ry].count += handle[rx].count;
                if (handle[rx].rank == handle[ry].rank) {
                    handle[ry].rank += 1;
                }
                return handle[ry].count;
            }
        } else {
            return handle[rx].count;
        }
    }

    bool in_same_set(int x, int y) {
        return find(x) == find(y);
    }

private:
    struct node {
        int p;
        int rank;
        int count;

        node() : p(0), rank(0), count(1) { }
    };

    std::vector<node> handle; // index is 1 based;
};

int main() {
    int ncase;
    std::cin >> ncase;

    for (int i = 0; i < ncase; ++i) {
        int n;
        std::cin >> n;

        int id = 1;
        std::map<std::string, int> idmap;

        disjoint_set s(200000);
        for (int j = 0; j < n; ++j) {
            std::string a, b;
            std::cin >> a >> b;

            if (idmap.count(a) == 0) {
                idmap[a] = id++;
            }

            if (idmap.count(b) == 0) {
                idmap[b] = id++;
            }

            std::cout << s.link(idmap[a], idmap[b]) << std::endl;

        }
    }
}

