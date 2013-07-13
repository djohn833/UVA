#include <stdio.h>

int k, x, y;

int
main()
{
    int n;

    while (scanf("%d", &k) == 1) {
        y = k + 1;
        n = 0;

        for (;;) {
            x = (k*y) / (y-k);
            if (x < y)
                break;
            if (k * (x+y) == x * y)
                n++;
            y++;
        }

        printf("%d\n", n);
        y = k + 1;
        for (;;) {
            x = (k*y) / (y-k);
            if (x < y)
                break;
            if (k * (x+y) == x * y)
                printf("1/%d = 1/%d + 1/%d\n", k, x, y);
            y++;
        }
    }

    return 0;
}
