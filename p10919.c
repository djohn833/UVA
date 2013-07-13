#include <stdio.h>
#include <string.h>

int k, m, c, r;
int courses[10000];

int
main()
{
    int i, j, p, grad, taken;

    while (scanf("%d %d", &k, &m) == 2) {
        memset(courses, 0, sizeof(courses));
        grad = 1;

        for (i = 0; i < k; i++) {
            scanf("%d", &j);
            courses[j] = 1;
        }

        for (i = 0; i < m; i++) {
            scanf("%d %d", &c, &r);
            taken = 0;

            for (j = 0; j < c; j++) {
                scanf("%d", &p);
                if (courses[p])
                    taken++;
            }

            if (taken < r)
                grad = 0;
        }

        printf("%s\n", grad ? "yes" : "no");
    }

    return 0;
}
