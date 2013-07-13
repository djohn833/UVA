#include <stdio.h>

int caseno, num_cases;
int L, W, H;

int
main()
{
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        scanf("%d %d %d", &L, &W, &H);
        printf("Case %d: %s\n",
            caseno,
            (L > 20 || W > 20 || H > 20) ? "bad" : "good");
    }

    return 0;
}
