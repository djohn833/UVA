#include <memory.h>
#include <stdio.h>

int N, M, C, K;
int caseno;
int money[201];

int
main()
{
    int i, j, k, p;
    scanf("%d", &N);

    for (caseno = 1; caseno <= N; caseno++) {
        scanf("%d %d", &M, &C);
        memset(money, 0, sizeof(money));
        money[0] = 1;
        printf("foo: %d\n", (1 << (C+2)) - 1);

        for (i = 1; i <= C; i++) {
            scanf("%d", &K);
            for (j = 0; j < K; j++) {
                scanf("%d", &p);
                for (k = M; k - p >= 0; k--) {
                    money[k] = money[k-p] | (1 << i);
                    if (money[k - p] & 1)
                        printf("money[%d] = %d\n", k, money[k]);
                }
            }
        }

        for (i = M; i >= 0; i--) {
            if (money[i] == (1 << (C+2)) - 1) {
                printf("%d\n", i);
                goto continue_outer;
            }
        }

        printf("no solution\n");

continue_outer:
        ;
    }

    return 0;
}
