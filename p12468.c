#include <stdio.h>
#include <stdlib.h>

int a, b;

int
min(int a, int b)
{
    return (a < b) ? a : b;
}

int
main()
{
    while (scanf("%d %d", &a, &b) == 2 && !(a == -1 && b == -1)) {
        if (a < b)
            printf("%d\n", min(b - a, 100 + a - b));
        else
            printf("%d\n", min(a - b, 100 + b - a));
    }

    return 0;
}
