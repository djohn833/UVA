#include <stdio.h>

typedef long long T;

int caseno;
int N, S[19];
T max, prods[19][19];

int main()
{
    int i, j;
    caseno = 1;

    while (scanf("%d", &N) == 1) {
        max = 0;

        for (i = 1; i <= N; i++) {
            scanf("%d", &S[i]);
            prods[i][i] = S[i];
            if (S[i] > max)
                max = S[i];

            for (j = i-1; j >= 1; j--) {
                prods[j][i] = prods[j][i-1] * S[i];
                if (prods[j][i] > max)
                    max = prods[j][i];
            }
        }

        printf("Case #%d: The maximum product is %lld.\n\n", caseno, max);

        caseno++;
    }

    return 0;
}
