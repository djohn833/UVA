#include <cstdio>
#include <iostream>
using namespace std;

enum Ori { N, E, S, W };
int L[] = { W, N, E, S };
int R[] = { E, S, W, N };

int grid[51][51];
int MAX_X, MAX_Y;
int x, y, px, py, ori;
bool lost;
char c;

int
char_to_ori(char c)
{
    switch (c) {
    case 'N':
        return N;
    case 'E':
        return E;
    case 'S':
        return S;
    case 'W':
        return W;
    }
}

char
ori_to_char(int ori)
{
    switch (ori) {
    case N:
        return 'N';
    case E:
        return 'E';
    case S:
        return 'S';
    case W:
        return 'W';
    }
}

int
main()
{
    cin >> MAX_X >> MAX_Y;

    while (cin >> x >> y >> c) {
        cin.ignore(256, '\n');

        ori = char_to_ori(c);
        lost = false;

        while (cin.get(c) && c != '\n') {
            if (!lost) {
                switch (c) {
                case 'L':
                    ori = L[ori];
                    break;
                case 'R':
                    ori = R[ori];
                    break;
                case 'F':
                    px = x;
                    py = y;

                    switch (ori) {
                    case N:
                        y += 1;
                        break;
                    case E:
                        x += 1;
                        break;
                    case S:
                        y -= 1;
                        break;
                    case W:
                        x -= 1;
                        break;
                    }

                    if (x < 0 || MAX_X < x || y < 0 || MAX_Y < y) {
                        x = px;
                        y = py;
                        if (!grid[x][y]) {
                            grid[x][y] = 1;
                            lost = true;
                        }
                    }
                    break;
                }
            }
        }

        printf("%d %d %c", x, y, ori_to_char(ori));
        if (lost)
            printf(" LOST");
        putchar('\n');
    }

    return 0;
}
