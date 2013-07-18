#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int caseno;
int N, Q;
int nums[10001], query;
int *it = &nums[1], *pos;

int
main()
{
    int i;
    caseno = 1;

    while (cin >> N >> Q && !(N == 0 && Q == 0)) {
        for (i = 1; i <= N; i++)
            cin >> nums[i];
        sort(it, it + N);

        /*
        if (caseno > 1)
            putchar('\n');
        //*/

        printf("CASE# %d:\n", caseno);

        for (i = 1; i <= Q; i++) {
            cin >> query;
            pos = lower_bound(it, it + N, query);
            if (*pos == query && pos != it + N)
                printf("%d found at %d\n", query, pos - nums);
            else
                printf("%d not found\n", query);
        }


        caseno++;
    }

    return 0;
}
