#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int caseno;
char grid[7][7];

int
main()
{
    int i, j, x, y, nx, ny;
    int invalid;
    char c;
    caseno = 1;

    while (cin.peek() != 'Z') {
        memset(grid, -1, sizeof(grid));
        invalid = 0;

        for (i = 1; i <= 5; i++) {
            for (j = 1; j <= 5; j++) {
                cin.get(c);
                grid[i][j] = c;
                if (c == ' ') {
                    y = i;
                    x = j;
                }
            }
            cin.ignore(256, '\n');
        }

        while (cin.get(c) && c != '0') {
            if (c == '\n' || invalid)
                continue;

            switch (c) {
            case 'A':
                nx = x;
                ny = y - 1;
                break;

            case 'B':
                nx = x;
                ny = y + 1;
                break;

            case 'L':
                nx = x - 1;
                ny = y;
                break;

            case 'R':
                nx = x + 1;
                ny = y;
                break;
            }

            if (grid[ny][nx] == -1)
                invalid = 1;

            grid[y][x]   = grid[ny][nx];
            grid[ny][nx] = ' ';
            x = nx;
            y = ny;
        }
        cin.ignore(256, '\n');

        if (caseno > 1)
            putchar('\n');

        cout << "Puzzle #" << caseno << ":\n";
        if (invalid)
            cout << "This puzzle has no final configuration.\n";
        else {
            for (i = 1; i <= 5; i++) {
                cout << grid[i][1];
                for (j = 2; j <= 5; j++) {
                    cout << " " << grid[i][j];
                }
                cout << "\n";
            }
        }

        caseno++;
    }

    return 0;
}
