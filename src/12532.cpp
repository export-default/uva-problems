#include <iostream>
#include <vector>

// https://uva.onlinejudge.org/external/125/p12532.pdf

template<typename T, typename V>
struct node {
    void assign(T t) { v = t; }

    void merge(node &left, node &right) { v = left.v * right.v; };

    V get() { return v; };

private:
    V v;
};

template<typename T, typename V>
struct segment_tree {

    segment_tree(const std::vector<T> &vec, int n) : nodes_(tree_size(n)), n_(n) {
        build_tree(vec, 1, 1, n);
    }

    int query(int i, int j) {
        auto nd = do_query(1, 1, n_, i, j);
        return nd.get();
    }

    void update(int pos, T val) {
        do_update(1, 1, n_, pos, val);
    }

private:

    void build_tree(const std::vector<T> &vec, int index, int node_low, int node_high) {
        if (node_low == node_high) {
            nodes_[index].assign(vec[node_low]);
        } else {
            int mid = (node_low + node_high) / 2;
            int left = left_child(index);
            int right = right_child(index);

            build_tree(vec, left, node_low, mid);
            build_tree(vec, right, mid + 1, node_high);

            nodes_[index].merge(nodes_[left], nodes_[right]);
        }
    }

    node<T, V> do_query(int index, int node_low, int node_high, int query_low, int query_high) {
        if (node_low == query_low && node_high == query_high) {
            return nodes_[index];
        } else {
            int node_mid = (node_low + node_high) / 2;
            int left = left_child(index);
            int right = right_child(index);

            if (query_low > node_mid) { // lie in right child
                return do_query(right, node_mid + 1, node_high, query_low, query_high);
            } else if (query_high <= node_mid) { // lie in left child
                return do_query(left, node_low, node_mid, query_low, query_high);
            } else {

                auto left_result = do_query(left, node_low, node_mid, query_low, node_mid);

                auto right_result = do_query(right, node_mid + 1, node_high, node_mid + 1, query_high);

                node<T, V> r;
                r.merge(left_result, right_result);
                return r;
            }
        }
    }

    void do_update(int index, int node_low, int node_high, int pos, T val) {
        if (node_low == node_high) {
            nodes_[index].assign(val);
        } else {
            int node_mid = (node_low + node_high) / 2;
            int left = left_child(index);
            int right = right_child(index);

            if (pos > node_mid) {
                do_update(right, node_mid + 1, node_high, pos, val);
            } else {
                do_update(left, node_low, node_mid, pos, val);
            }

            nodes_[index].merge(nodes_[left], nodes_[right]);
        }
    }


    int tree_size(int leaf) {
        int size = 1;
        for (; size < leaf; size <<= 1);
        return size << 1;
    }

    int left_child(int n) { return n << 1; }

    int right_child(int n) { return (n << 1) + 1; }

private:
    std::vector<node<T, V>> nodes_;
    int n_;
};

int sign(int n) {
    return n > 0 ? 1 : n == 0 ? 0 : -1;
}

int main() {
    int n, k;
    while (std::cin >> n >> k) {

        std::vector<int> vec(n + 1);
        for (int i = 1; i <= n; ++i) {
            int tmp;
            std::cin >> tmp;
            vec[i] = sign(tmp);
        }

        segment_tree<int, int> st(vec, n);
        for (int m = 0; m < k; ++m) {
            char cmd;
            int i, j;
            std::cin >> cmd >> i >> j;
            if (cmd == 'C') {
                st.update(i, sign(j));
            } else if (cmd == 'P') {
                int p = st.query(i, j);
                if (p > 0) {
                    std::cout << "+";
                } else if (p < 0) {
                    std::cout << "-";
                } else {
                    std::cout << "0";
                }
            }
        }

        std::cout << std::endl;
    }
}


