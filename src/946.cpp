#include <iostream>
#include <vector>
#include <limits>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=887

struct Box {
    int length;
    std::vector<Box *> container;
    int bottom_height;

    Box(int len) : length{len}, bottom_height{0} { }

    bool put(int box_len) {

        if (box_len > length) {
            return false;
        }

        for (Box *box : container) {
            if (box->put(box_len)) {
                return true;
            }
        }

        if (length - bottom_height >= box_len) {
            container.push_back(new Box(box_len));
            bottom_height += box_len;
            return true;
        }
        return false;
    }

    void clear() {
        for (Box *box : container) {
            delete box;
        }
        container.clear();
        bottom_height = 0;
    }

    ~Box() {
        clear();
    }

};

int main() {
    std::string line;

    while (std::cin >> line) {
        if(!line.empty()){
            int n_box = std::stoi(line);
            Box world(std::numeric_limits<int>::max());
            for (int i = 0; i < n_box; ++i) {
                std::cin >> line;
                world.put(std::stoi(line));
            }
            std::cout << world.bottom_height << std::endl;
        }
    }
}