#include <stdio.h>
#include <string.h>

int caseno;
int W, H, N;
int grid[502][502];
int total;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int
main()
{
    caseno = 1;

    while (scanf("%d %d %d", &W, &H, &N) && !(W == 0 && H == 0 && N == 0)) {
        int i, x, y, x1, y1, x2, y2;

        for (y = 1; y <= H; y++)
            for (x = 1; x <= W; x++)
                grid[y][x] = 1;

        total = W * H;

        for (i = 0; i < N; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            for (y = min(y1, y2); y <= max(y1, y2); y++) {
                for (x = min(x1, x2); x <= max(x1, x2); x++) {
                    if (grid[y][x]) {
                        grid[y][x] = 0;
                        total--;
                    }
                }
            }
        }

        if (total == 0)
            printf("There is no empty spots.\n");
        else if (total == 1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n", total);

        caseno++;
    }

    return 0;
}
