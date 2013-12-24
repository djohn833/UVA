#include <stdio.h>
#include <string.h>

int caseno, num_cases;

int
main()
{
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        int x, y, grid[34][34] = { 0 };
        int c;
        scanf("%d %d", &x, &y);

        while ((c = getchar()) != EOF && c != '\n') {}

        while ((c = getchar()) != EOF && c != '\n') {
            if (c == 'N') {
                grid[y][x] = 1;
                y++;
            } else if (c == 'S') {
                grid[y - 1][x - 1] = 1;
                y--;
            } else if (c == 'E') {
                grid[y - 1][x] = 1;
                x++;
            } else if (c == 'W') {
                grid[y][x - 1] = 1;
                x--;
            }

#ifndef ONLINE_JUDGE
            printf("%d %d\n", x, y);
#endif
        }

        printf("Bitmap #%d\n", caseno);
        for (y = 31; y >= 0; y--) {
            for (x = 0; x < 32; x++)
                putchar(grid[y][x] ? 'X' : '.');
            putchar('\n');
        }

        putchar('\n');
    }

    return 0;
}
