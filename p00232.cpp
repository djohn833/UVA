#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int caseno;
string line;
char grid[12][12];
int across[12][12], down[12][12];
int r, c;
int n;

int
main()
{
    int i, j, k;
    caseno = 1;

    while (getline(cin, line)) {
        stringstream in(line);
        if (!(in >> r >> c))
            break;

        memset(grid, '*', sizeof(grid));
        memset(across, 0, sizeof(across));
        memset(down, 0, sizeof(down));
        n = 1;

        for (i = 1; i <= r; i++) {
            for (j = 1; j <= c; j++) {
                char tmp;
                cin.get(tmp);
                grid[i][j] = tmp;
            }
            cin.ignore(256, '\n');
        }

        for (i = 1; i <= r; i++) {
            for (j = 1; j <= c; j++) {
                if (grid[i][j] != '*' && (grid[i-1][j] == '*' || grid[i][j-1] == '*')) {
                    if (grid[i-1][j] == '*')
                        down[i][j] = n;
                    if (grid[i][j-1] == '*')
                        across[i][j] = n;
                    n++;
                }
            }
        }

        if (caseno > 1)
            putchar('\n');

        printf("puzzle #%d:\n", caseno);

        printf("Across\n");
        for (i = 1; i <= r; i++) {
            for (j = 1; j <= c; j++) {
                //printf("across[%d][%d] = %d\n", i, j, across[i][j]);
                if (across[i][j]) {
                    printf("%3d.", across[i][j]);
                    for (k = j; grid[i][k] != '*'; k++) {
                        putchar(grid[i][k]);
                    }
                    putchar('\n');
                }
            }
        }

        printf("Down\n");
        for (i = 1; i <= r; i++) {
            for (j = 1; j <= c; j++) {
                //printf("down[%d][%d] = %d\n", i, j, down[i][j]);
                if (down[i][j]) {
                    printf("%3d.", down[i][j]);
                    for (k = i; grid[k][j] != '*'; k++) {
                        putchar(grid[k][j]);
                    }
                    putchar('\n');
                }
            }
        }

        caseno++;
    }

    return 0;
}
