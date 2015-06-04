#include <iostream>

// https://uva.onlinejudge.org/external/1/112.html

using namespace std;

struct node {
    int value;
    node *left;
    node *right;

    node() : value(0), left(nullptr), right(nullptr) {

    }
};

void construct_tree(node *&root) {
    char open, close;
    std::cin >> open;

    auto next = (cin >> std::ws).peek(); // #
    if (next == ')') {
        root = nullptr;
    } else {
        root = new node();
        std::cin >> root->value;
        construct_tree(root->left);
        construct_tree(root->right);
    }
    std::cin >> close;
}


bool findout(node *root, int n) {
    if (root == nullptr) {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->value == n;
    } else {
        return findout(root->left, n - root->value) || findout(root->right, n - root->value);
    }
}

void free(node *&root) {

    if (root != nullptr) {
        free(root->left);
        free(root->right);
        delete root;
        root = nullptr;
    }

}

int main() {
    int n;
    while (cin >> n) {
        node *root = nullptr;
        construct_tree(root);
        if (!findout(root, n)) {
            std::cout << "no" << std::endl;
        } else {
            std::cout << "yes" << std::endl;
        }
        free(root);
    }
}

