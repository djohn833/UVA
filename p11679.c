#include <stdio.h>

int b, n, r[21];
int d, c, v;

int
main()
{
    int i, good;

    while (scanf("%d %d", &b, &n) && !(b == 0 && n == 0)) {
        for (i = 1; i <= b; i++)
            scanf("%d", &r[i]);

        for (i = 1; i <= n; i++) {
            scanf("%d %d %d", &d, &c, &v);
            r[d] -= v;
            r[c] += v;
        }

        good = 1;
        for (i = 1; i <= b; i++)
            if (r[i] < 0)
                good = 0;

        printf("%s\n", good ? "S" : "N");
    }

    return 0;
}
