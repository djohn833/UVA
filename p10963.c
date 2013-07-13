#include <stdio.h>

int caseno, num_cases;

int W, diff, prevdiff;

int
main()
{
    int i, a, b, fit;

    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        scanf("%d %d %d", &W, &a, &b);
        fit = 1;
        diff = a - b;

        for (i = 1; i < W; i++) {
            prevdiff = diff;
            scanf("%d %d", &a, &b);
            diff = a - b;
            fit &= prevdiff == diff;
        }

        if (caseno > 1)
            putchar('\n');
        printf("%s\n", fit ? "yes" : "no");
    }

    return 0;
}
