#include <cstdio>
#include <iostream>
using namespace std;

char grid[11][11];
int steps[11][11];
int maxr, maxc;
int r, c, start, nsteps;

int
main()
{
    while (cin >> maxr >> maxc >> start &&
           !(maxr == 0 && maxc == 0 && start == 0)) {
        for (r = 1; r <= maxr; r++) {
            for (c = 1; c <= maxc; c++) {
                cin >> grid[r][c];
                steps[r][c] = -1;
            }
        }

        r = 1;
        c = start;
        nsteps = 0;

        for (;;) {
            steps[r][c] = nsteps;

            switch (grid[r][c]) {
            case 'N':
                r--;
                break;
            case 'S':
                r++;
                break;
            case 'W':
                c--;
                break;
            case 'E':
                c++;
                break;
            }

            nsteps++;

            if (r < 1 || maxr < r || c < 1 || maxc < c)
                goto found_exit;

            if (steps[r][c] >= 0)
                goto found_loop;
        }

found_exit:
        printf("%d step(s) to exit\n", nsteps);
        continue;

found_loop:
        printf("%d step(s) before a loop of %d step(s)\n",
            steps[r][c],
            nsteps - steps[r][c]);
        continue;
    }

    return 0;
}
