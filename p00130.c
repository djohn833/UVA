#include <stdio.h>

int caseno;
int n, k, i;

int alive[101];

int
main(void)
{
    int i, p, q;
    caseno = 1;

    while (scanf("%d %d %d", &N, &k, &m) && !(N == 0 && k == 0 && m == 0)) {
        for (i = 1; i <= N; i++)
            in_queue[i] = 1;

        p = N;
        q = 1;
        n = N;

        for (;;) {
            for (i = 0; i < k;) {
                p = p < N ? p + 1 : 1;
                if (in_queue[p])
                    i++;
            }
            for (i = 0; i < m;) {
                q = 1 < q ? q - 1 : N;
                if (in_queue[q])
                    i++;
            }

            if (p == q) {
                printf("% 3d", p);
                n -= 1;
            } else {
                printf("% 3d% 3d", p, q);
                n -= 2;
            }
            in_queue[p] = in_queue[q] = 0;

            if (n == 0)
                break;

            printf(",");
        }

        printf("\n");

        caseno++;
    }

    return 0;
}
