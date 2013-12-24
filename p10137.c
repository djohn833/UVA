#include <stdio.h>
#include <string.h>

int caseno;
int n;
int students[1000];
int dollars, cents;

int
cmp(const void *lhs, const void *rhs)
{
    return *(int *) lhs - *(int *) rhs;
}

int
main()
{
    int i, t, min, total;
    caseno = 1;

    while (scanf("%d", &n) == 1 && n != 0) {
        for (i = 0; i < n; i++) {
            scanf("%d.%d", &dollars, &cents);
            students[i] = 100*dollars + cents;
        }

        qsort(students, n, sizeof(int), cmp);

        min = students[0];
        total = 0;

        for (i = 0; i < n; i++) {
            /*students[i] -= min;*/
            /*printf("$%d.%02d\n", students[i] / 100, students[i] % 100);*/
        }

        for (i = 0; i < n/2; i++) {
            t = (students[n - 1 - i] - students[i]) / 2;
            students[i] += t;
            students[n - 1 - i] -= t;
            total += t;
        }

        for (i = 0; i < n; i++) {
            /*printf("$%d.%02d\n", students[i] / 100, students[i] % 100);*/
        }


        printf("$%d.%02d\n", total / 100, total % 100);

        caseno++;
    }

    return 0;
}
