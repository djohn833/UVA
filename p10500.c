#include <stdio.h>
#include <string.h>

int caseno;
int N, M;
int x, y, x_ini, y_ini;
char grid[12][12], robot[12][12];
int visit[12][12];
int num_moves, move;

int dx[] = { -1,  0,  1,  0 };
int dy[] = {  0,  1,  0, -1 };

void
print_border()
{
    int i;
    for (i = 0; i < M; i++)
        printf("|---");
    printf("|\n");
}

int
main()
{
    int i;
    caseno = 1;

    while (scanf("%d %d", &N, &M) && !(N == 0 && M == 0)) {
        scanf("%d %d", &x_ini, &y_ini);

        memset(grid, 'X', sizeof grid);
        memset(robot, '?', sizeof robot);
        memset(visit, 0, sizeof visit);

        for (x = 1; x <= N; x++)
            for (y = 1; y <= M; y++)
                scanf(" %c ", &grid[x][y]);

        x = x_ini;
        y = y_ini;
        robot[x][y] = '0';
        num_moves = 0;

        for (;;) {
            visit[x][y] = 1;
            move = -1;

            for (i = 0; i < 4; i++) {
                robot[x + dx[i]][y + dy[i]] = grid[x + dx[i]][y + dy[i]];

                if (move == -1 &&
                        !visit[x + dx[i]][y + dy[i]] &&
                        grid[x + dx[i]][y + dy[i]] == '0')
                    move = i;
            }

            if (move == -1)
                break;

            x += dx[move];
            y += dy[move];
            num_moves++;
        }

        putchar('\n');
        print_border();
        for (x = 1; x <= N; x++) {
            for (y = 1; y <= M; y++)
                printf("| %c ", robot[x][y]);
            printf("|\n");
            print_border();
        }

        printf("\nNUMBER OF MOVEMENTS: %d\n", num_moves);

        caseno++;
    }

    return 0;
}
