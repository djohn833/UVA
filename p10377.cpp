#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int caseno, num_cases;

char grid[62][62];
int nrows, ncols;
int r, c, pr, pc;

enum { N, E, S, W };
int L[] = { W, N, E, S };
int R[] = { E, S, W, N };
char ori_name[] = "NESW";
int ori;

char cmd;

int
main()
{
    cin >> num_cases;

    for (caseno = 1; caseno <= num_cases; caseno++) {
        cin >> nrows >> ncols;
        cin.ignore(256, '\n');
        memset(grid, '#', sizeof(grid));

        for (r = 1; r <= nrows; r++) {
            for (c = 1; c <= ncols; c++) {
                cin.get(grid[r][c]);
            }
            cin.ignore(256, '\n');
        }

        cin >> r >> c;
        ori = N;

        while (cin.get(cmd) && cmd != 'Q') {
            switch (cmd) {
            case 'L':
                ori = L[ori];
                break;
            case 'R':
                ori = R[ori];
                break;
            case 'F':
                pr = r;
                pc = c;

                switch (ori) {
                case N:
                    r--;
                    break;
                case S:
                    r++;
                    break;
                case W:
                    c--;
                    break;
                case E:
                    c++;
                    break;
                }

                if (grid[r][c] == '*') {
                    r = pr;
                    c = pc;
                }
                break;
            }
        }

        if (caseno > 1)
            putchar('\n');
        printf("%d %d %c\n", r, c, ori_name[ori]);
    }

    return 0;
}
