#include <stdio.h>

int caseno;
int S, prob[12], req[12];

int
main()
{
    int i;
    caseno = 1;

    while (scanf("%d", &S) == 1 && S >= 0) {
        for (i = 0; i < 12; i++)
            scanf("%d", &prob[i]);
        for (i = 0; i < 12; i++)
            scanf("%d", &req[i]);

        if (caseno > 1)
            putchar('\n');
        printf("Case %d:\n", caseno++);
        for (i = 0; i < 12; i++) {
            if (S >= req[i]) {
                printf("No problem! :D\n");
                S -= req[i];
            } else
                printf("No problem. :(\n");

            S += prob[i];
        }
    }

    return 0;
}
