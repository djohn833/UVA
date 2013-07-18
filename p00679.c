#include <stdio.h>
#include <string.h>

int caseno, num_cases;
int D, I;

int
main()
{
    int i, P;
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        /*
        if (caseno > 1)
            putchar('\n');
        //*/

        scanf("%d %d", &D, &I);

        I--;
        P = 1;
        for (i = 1; i < D; i++) {
            P = ((I & (1<<(i-1))) == 0) ? 2*P : 2*P + 1;
        }

        printf("%d\n", P);
    }

    return 0;
}
