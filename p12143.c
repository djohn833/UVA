#include <stdio.h>

typedef unsigned long long T;

T
f(T n)
{
    T i, j, k, l, m, tmp, sum = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                for (l = 0; l < n; l++) {
                    for (m = 0; m < n; m++) {
                        tmp = (abs(i-j) * abs(j-k) * abs(k-l) * abs(l-m) * abs(m-i));
                        sum = (sum + tmp);
                    }
                }
            }
        }
    }

    return sum;
}

T
g(T n)
{
    T coeff[] = { 0, 0, 120, 2840, 23080, 92120, 207280, 276960, 218480, 94160, 17120 };
    T sum = 0;
    int i;

    for (i = 11; i >= 0; i--) {
        sum += (
    }
}

int
main()
{
    T n;

    while (scanf("%d", &n) == 1 && n != 0) {
        printf("%llu\n", f(n));
    }

    return 0;
}
