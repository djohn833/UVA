#include <stdio.h>

int dur, dep;
double down, amount;
double dep_rec[101];

int
main()
{
    int i, j, k;
    double d, val, loan;

    while (scanf("%d %lf %lf %d", &dur, &down, &amount, &dep) == 4 &&
            dur >= 0) {
        for (i = 0; i < dep; i++) {
            scanf("%d %lf", &k, &d);
            for (j = k; j <= dur; j++) {
                dep_rec[j] = d;
            }
        }

        val = down + amount;
        val -= val * dep_rec[0];
        loan = amount;
        for (i = 1; i <= dur; i++) {
            val -= val * dep_rec[i];
            loan -= amount / dur;
            if (loan < val)
                break;
        }

        if (i == 1)
            printf("1 month\n");
        else
            printf("%d months\n", i);
    }

    return 0;
}
