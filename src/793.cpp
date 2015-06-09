#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <limits>
#include <vector>

// https://uva.onlinejudge.org/external/7/p793.pdf

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

    void link(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) { // link by rank
            if (handle[rx].rank == handle[ry].rank) {
                handle[rx].p = ry;
                handle[ry].rank += 1;
            } else if (handle[rx].rank < handle[ry].rank) {
                handle[rx].p = ry;
            } else {
                handle[ry].p = rx;
            }
        }
    }

    bool in_same_set(int x, int y) {
        return find(x) == find(y);
    }

private:
    constexpr static int NIL = -1;

    struct node {
        int p;
        int rank;

        node() : p(NIL), rank(0) { }
    };

    std::vector<node> handle; // index is 1 based;
};


int main() {
    int ncase;
    std::cin >> ncase;
    for (int i = 0; i < ncase; ++i) {
        int n;
        std::cin >> n;
        disjoint_set s(n);
        int sc(0), fc(0);

        std::string line;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (std::getline(std::cin, line) && line != "") {
            std::istringstream ss(line);
            char cmd;
            int x, y;
            ss >> cmd >> x >> y;
            if (cmd == 'c') {
                s.link(x, y);
            } else if (cmd == 'q') {
                if (s.in_same_set(x, y)) {
                    sc++;
                } else {
                    fc++;
                }
            }
        }

        std::cout << sc << "," << fc << std::endl;
        if (i != ncase - 1) {
            std::cout << std::endl;
        }
    }
}