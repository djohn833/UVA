#include <stdio.h>

int N, cur;
int max, curmax[10001];

int
main()
{
    int i, j;

    while (scanf("%d", &N) == 1 && N != 0) {
        max = curmax[0] = 0;

        for (i = 1; i <= N; i++) {
            scanf("%d", &cur);

            if (curmax[i-1] + cur >= cur)
                curmax[i] = curmax[i-1] + cur;
            else
                curmax[i] = cur;

            if (curmax[i] > max)
                max = curmax[i];
        }

        if (max > 0)
            printf("The maximum winning streak is %d.\n", max);
        else
            printf("Losing streak.\n");
    }

    return 0;
}
