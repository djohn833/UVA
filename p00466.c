#include <stdio.h>

char pat1[11][11], pat2[11][11];

int N;

int
check(int rot, int flip)
{
    int i, j, r, c, t, match;

    match = 1;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            r = i;
            c = j;

            if (flip)
                r = N - i - 1;

            switch (rot) {
            case 0:
                break;

            case 1:
                t = r;
                r = c;
                c = N - t - 1;
                break;

            case 2:
                r = N - r - 1;
                c = N - c - 1;
                break;

            case 3:
                t = c;
                c = r;
                r = N - t - 1;
                break;
            }

            if (pat1[i][j] != pat2[r][c])
                match = 0;
        }
    }

    return match;
}

int
main(void)
{
    int i, j;
    int caseno;

    caseno = 1;

    while (scanf("%d", &N) == 1) {
        for (i = 0; i < N; i++) {
            scanf("%s", &pat1[i]);
            scanf("%s", &pat2[i]);
        }

#if 0
        printf("%d\n", N);

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%c", pat1[i][j]);
            }
            printf("\n");
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%c", pat2[i][j]);
            }
            printf("\n");
        }
#endif

        if (check(0, 0))
            printf("Pattern %d was preserved.\n", caseno++);
        else if (check(1, 0))
            printf("Pattern %d was rotated 90 degrees.\n", caseno++);
        else if (check(2, 0))
            printf("Pattern %d was rotated 180 degrees.\n", caseno++);
        else if (check(3, 0))
            printf("Pattern %d was rotated 270 degrees.\n", caseno++);
        else if (check(0, 1))
            printf("Pattern %d was reflected vertically.\n", caseno++);
        else if (check(1, 1))
            printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", caseno++);
        else if (check(2, 1))
            printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", caseno++);
        else if (check(3, 1))
            printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", caseno++);
        else
            printf("Pattern %d was improperly transformed.\n", caseno++);
    }

    return 0;
}

