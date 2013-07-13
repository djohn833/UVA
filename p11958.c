#include <limits.h>
#include <stdio.h>

int caseno, num_cases;
int K, cur, t, h, m, q, dur;
int min;

int
main()
{
    int i;
    scanf("%d", &num_cases);

    for (caseno = 1; caseno <= num_cases; caseno++) {
        scanf("%d %d:%d", &K, &h, &m);
        cur = h * 60 + m;

        min = INT_MAX;

        for (i = 0; i < K; i++) {
            scanf("%d:%d %d", &h, &m, &q);
            t = h * 60 + m + q;

            dur = t - cur;
            if (dur < 0)
                dur += 24*60;

            if (dur < min)
                min = dur;
        }

        printf("Case %d: %d\n", caseno, min);
    }

    return 0;
}
