#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

// http://uva.onlinejudge.org/external/100/p10003.pdf

using namespace std;

int mcost(vector<int> cuts) {
    static int cost[51][51]; // cost[i][j] 表示 第i个切割点与第j个切割点之间的线段，切割的最小cost。

    memset(cost, 0, sizeof(cost));

    // len = 1, 相邻两个切割点，cost=0

    for (int len = 2; len <= cuts.size() - 1; ++len) {
        for (int i = 0; i < cuts.size() - len; ++i) {
            int mincost = numeric_limits<int>::max();

            int c = cuts[i + len] - cuts[i];
            for (int j = i + 1; j < i + len; ++j) {
                mincost = min(mincost, c + cost[i][j] + cost[j][i + len]);
            }
            cost[i][i + len] = mincost;
        }
    }

    return cost[0][cuts.size() - 1];
}

int main() {
    int len;
    while (cin >> len && len != 0) {
        int n;
        cin >> n;
        vector<int> cuts;

        cuts.push_back(0);
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            cuts.push_back(tmp);
        }
        cuts.push_back(len);

        cout << "The minimum cutting is " << mcost(cuts) << "." << endl;
    }
}
