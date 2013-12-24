#include <math.h>
#include <stdio.h>
#include <string.h>

int caseno;
int N;
int x, y;

int
cube(int n)
{
    return n * n * n;
}

int
main(void)
{
    double tmp;
    caseno = 1;

    while (scanf("%d", &N) == 1 && N != 0) {
        for (y = 1; y < cube(N); y++) {
            tmp = pow(N + cube(y), 1.0 / 3.0);
            x = ceil(tmp);
            printf("y = %d, cube = %d, cuberoot = %lf, x = %d\n", y, cube(y), tmp, x);
            if (N == cube(x) - cube(y))
                break;
        }

        if (N == cube(x) - cube(y))
            printf("%d %d\n", x, y);
        else
            printf("No solution\n");

        caseno++;
    }

    return 0;
}
