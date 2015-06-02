#include <iostream>
#include <string>

// https://uva.onlinejudge.org/external/118/p11831.pdf

char map[101][101]; // arena
int nrows, ncols, ops_len;
int x, y; // robot locations
std::string ops; // instructions
int score;

void move(char op) {
    if (op == 'D') {
        switch (map[x][y]) {
            case 'N':
                map[x][y] = 'L';
                break;
            case 'S':
                map[x][y] = 'O';
                break;
            case 'L':
                map[x][y] = 'S';
                break;
            case 'O':
                map[x][y] = 'N';
                break;
            default:
                abort();
        }
        return;
    }

    if (op == 'E') {
        switch (map[x][y]) {
            case 'N':
                map[x][y] = 'O';
                break;
            case 'S':
                map[x][y] = 'L';
                break;
            case 'L':
                map[x][y] = 'N';
                break;
            case 'O':
                map[x][y] = 'S';
                break;
            default:
                abort();
        }
        return;
    }

    if (op == 'F') {
        int next_x, next_y;
        switch (map[x][y]) {
            case 'N':
                next_x = x - 1;
                next_y = y;
                break;
            case 'S':
                next_x = x + 1;
                next_y = y;
                break;
            case 'L':
                next_x = x;
                next_y = y + 1;
                break;
            case 'O':
                next_x = x;
                next_y = y - 1;
                break;
            default:
                abort();
        }

        if (next_x < 1 || next_x > nrows || next_y < 1 || next_y > ncols || map[next_x][next_y] == '#') {
            return;
        } else {
            char orient = map[x][y];
            map[x][y] = '.';
            x = next_x;
            y = next_y;
            if (map[x][y] == '*') {
                score++;
            }
            map[x][y] = orient;
        }
    }


}

int main() {
    while (std::cin >> nrows >> ncols >> ops_len && !(nrows == 0 && ncols == 0 && ops_len == 0)) {
        score = 0;
        for (int i = 1; i <= nrows; ++i) {
            for (int j = 1; j <= ncols; ++j) {
                std::cin >> map[i][j];
                switch (map[i][j]) {
                    case 'N':
                    case 'S':
                    case 'L':
                    case 'O':
                        x = i;
                        y = j;
                        break;
                    default:
                        break;
                }
            }
        }
        std::cin >> ops;
        for (const char &ch : ops) {
            move(ch);
        }
        std::cout << score << std::endl;
    }
}