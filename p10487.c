#include <stdio.h>
#include <stdlib.h>

int caseno;
int n, m, q, nums[1000];
int nearest;

int
main()
{
    int i, j, k;
    caseno = 1;

    while (scanf("%d", &n) == 1 && n != 0) {
        for (i = 0; i < n; i++)
            scanf("%d", &nums[i]);

        printf("Case %d:\n", caseno++);
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            scanf("%d", &q);
            nearest = nums[0] + nums[1];

            for (j = 0; j < n; j++) {
                for (k = j+1; k < n; k++) {
                    if (abs(nums[j] + nums[k] - q) < abs(nearest - q))
                        nearest = nums[j] + nums[k];
                    if (nearest == q)
                        goto print_ans;
                }
            }

print_ans:
            printf("Closest sum to %d is %d.\n", q, nearest);
        }
    }

    return 0;
}
