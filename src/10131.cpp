#include <iostream>
#include <vector>
#include <algorithm>

// http://uva.onlinejudge.org/external/101/p10131.pdf
// case
// 8 20
// 9 15
// 15 25
// 19 10


struct elephant {
    int first; // w
    int second; // s
    int index; // 1-based

    bool operator<(const elephant &rhs) const {
        return first < rhs.first || (first == rhs.first && second > rhs.second);
    }
};

constexpr int NIL = -1;

void print_path(const std::vector<elephant> &vec, const std::vector<int> &path,
                std::vector<int>::difference_type index) {
    if (index != NIL) {
        print_path(vec, path, path[index]);
        std::cout << vec[index].index << std::endl;
    }
}

int main() {
    int w, s, c;
    std::vector<elephant> vec;
    c = 1;
    while (std::cin >> w >> s) {
        vec.emplace_back(elephant{w, s, c++});
    }

    std::sort(vec.begin(), vec.end());

    std::vector<int> maxlen_ending_here;
    std::vector<int> predecessor;

    for (int i = 0; i < vec.size(); ++i) {
        int pred = NIL;
        int pred_max = -1;
        for (int j = i - 1; j >= 0; --j) {
            // 不能只看第一个比它小的。
            if (vec[j].first < vec[i].first && vec[j].second > vec[i].second && maxlen_ending_here[j] > pred_max) {
                pred = j;
                pred_max = maxlen_ending_here[j];
            }
        }
        if (pred == NIL) {
            maxlen_ending_here.push_back(1);
            predecessor.push_back(NIL);
        } else {
            maxlen_ending_here.push_back(pred_max + 1);
            predecessor.push_back(pred);
        }
    }

    auto maxlen = std::max_element(maxlen_ending_here.begin(), maxlen_ending_here.end());
    std::cout << (*maxlen) << std::endl;

    print_path(vec, predecessor, std::distance(maxlen_ending_here.begin(), maxlen));

}
