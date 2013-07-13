#include <stdio.h>
#include <string.h>

int caseno;
int n, m, c;
int current[21], state[21];
int max, curr;

int
main()
{
    int i, k;
    caseno = 1;

    while (scanf("%d %d %d", &n, &m, &c) == 3 &&
           !(n == 0 && m == 0 && c == 0)) {
        max = curr = 0;
        memset(state, 0, sizeof(state));

        for (i = 1; i <= n; i++)
            scanf("%d", &current[i]);

        for (i = 1; i <= m; i++) {
            scanf("%d", &k);

            state[k] ^= 1;
            curr += current[k] * (state[k] ? 1 : -1);
            if (curr > max)
                max = curr;
        }

        printf("Sequence %d\n", caseno++);
        if (max > c)
            printf("Fuse was blown.\n");
        else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n", max);
        }

        putchar('\n');
    }

    return 0;
}
