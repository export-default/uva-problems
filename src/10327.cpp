#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/103/p10327.pdf

int _merge(std::vector<int> &vec, int start, int mid, int end) {
    int count = 0;
    int i = start;
    int j = mid;
    std::vector<int> tmp;
    while (i < mid && j < end) {
        if (vec[i] <= vec[j]) {
            tmp.push_back(vec[i++]);
        } else {
            tmp.push_back(vec[j++]);
            count += (mid - i);
        }
    }

    while (i < mid) {
        tmp.push_back(vec[i++]);
    }

    while (j < end) {
        tmp.push_back(vec[j++]);
    }

    for (int k = 0; k < tmp.size(); ++k) {
        vec[start + k] = tmp[k];
    }

    return count;
}

// [start,end)
int _iver_count(std::vector<int> &vec, int start, int end) {
    int count = 0;
    if (start < end - 1) {
        int mid = (start + end) / 2;
        count += _iver_count(vec, start, mid);
        count += _iver_count(vec, mid, end);

        count += _merge(vec, start, mid, end);
    }
    return count;
}

int inversion_count(std::vector<int> &vec) {
    return _iver_count(vec, 0, (int) vec.size());
}


int main() {
    int n;
    while (std::cin >> n) {
        std::vector<int> vec;
        for (int i = 0; i < n; ++i) {
            int tmp;
            std::cin >> tmp;
            vec.push_back(tmp);
        }
        std::cout << "Minimum exchange operations : " << inversion_count(vec) << std::endl;
    }
}
