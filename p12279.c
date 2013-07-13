#include <stdio.h>

int caseno;
int N, k, bal;

int
main()
{
    int i;
    caseno = 1;

    while (scanf("%d", &N) == 1 && N != 0) {
        bal = 0;

        for (i = 0; i < N; i++) {
            scanf("%d", &k);
            bal += (k > 0) ? 1 : -1;
        }

        printf("Case %d: %d\n", caseno++, bal);
    }

    return 0;
}
