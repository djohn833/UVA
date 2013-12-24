#include <stdio.h>
#include <string.h>

int caseno, num_cases;

int
main()
{
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        int n, k;
        scanf("%d %d", &n, &k);

        printf("%d\n", k ^ (k >> 1));
    }

    return 0;
}
