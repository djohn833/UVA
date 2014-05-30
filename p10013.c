#include <stdio.h>
#include <string.h>

int caseno, num_cases;
int M;
int i, j, n;
int a, b;

int p[] = { 1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9 };
int total[111111 + 100];

int
main()
{
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        memset(total, 0, sizeof(total));
        if (caseno > 1)
            putchar('\n');

        scanf("%d", &M);
        for (i = 0, j = 0, n = 1; n <= M; n++) {
            i++;
            if (i == 10) {
                i = 1;
                j++;
            }

            scanf("%d %d", &a, &b);
            total[j] += (a + b) * p[9 - i];
        }

        for (n = j; n > 0; n--) {
            if (total[n] / p[9] > 0) {
                total[n-1] += total[n] / p[9];
                total[n] %= p[9];
            }
        }

        if (j >= 1)
            printf("%09d", total[0]);
        for (n = 1; n < j; n++) {
            printf("%09d", total[n]);
        }
        printf("%0*d\n", i, total[j] / p[9 - i]);
    }

    return 0;
}

