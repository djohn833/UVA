#include <stdio.h>
#include <limits.h>

int caseno, num_cases;
int s, nice[20001];
int max, maxend, curmax[20001], start[20001];

int
main()
{
    int i, j;
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        scanf("%d", &s);
        max = curmax[1] = 0;
        maxend = start[1] = 1;

        for (i = 2; i <= s; i++) {
            scanf("%d", &nice[i]);

            if (curmax[i-1] + nice[i] >= nice[i]) {
                curmax[i] = curmax[i-1] + nice[i];
                start[i] = start[i-1];
            } else {
                curmax[i] = nice[i];
                start[i] = i - 1;
            }

            if (curmax[i] > max ||
                (curmax[i] == max && i - start[i] > maxend - start[maxend])) {
                max = curmax[i];
                maxend = i;
            }
        }

        if (max > 0)
            printf("The nicest part of route %d is between stops %d and %d\n",
                caseno, start[maxend], maxend);
        else
            printf("Route %d has no nice parts\n", caseno);
    }

    return 0;
}
