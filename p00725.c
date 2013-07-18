#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caseno;
int N, num_sols;
int digit[6], used;

void
search(int k)
{
    int i, num, den, tmp;

    for (i = 0; i < 10; i++) {
        if ((used & (1<<i)) == 0) {
            used |= 1 << i;
            digit[k] = i;

            if (k == 5) {
                num = 10000*digit[1] + 1000*digit[2] + 100*digit[3] +
                    10*digit[4] + digit[5];
                den = num / N;
                tmp = used |
                    (1 << ((den / 10000) % 10)) |
                    (1 << ((den / 1000) % 10)) |
                    (1 << ((den / 100) % 10)) |
                    (1 << ((den / 10) % 10)) |
                    (1 << ((den / 1) % 10));

                if (num % N == 0 && tmp == ((1<<10) - 1)) {
                    printf("%05d / %05d = %d\n", num, den, N);
                    num_sols++;
                }
            } else
                search(k + 1);

            used &= ~(1 << i);
        }
    }
}

int
main()
{
    caseno = 1;

    while (scanf("%d", &N) == 1 && N != 0) {
        num_sols = used = 0;

        if (caseno++ > 1)
            putchar('\n');

        search(1);
        if (num_sols == 0)
            printf("There are no solutions for %d.\n", N);
    }

    return 0;
}
