#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int caseno = 1;

int
main()
{
    vector<int> missles, lis;
    int i, j, k, ans, maxans;

    while (cin >> k && k != -1) {
        missles.clear();
        missles.push_back(k);

        while (cin >> k && k != -1)
            missles.push_back(k);

        maxans = 1;
        lis.clear();
        lis.push_back(1);
        for (i = 1; i < missles.size(); i++) {
            ans = 1;
            for (j = 0; j < i; j++)
                if (missles[i] < missles[j])
                    ans = max(ans, 1 + lis[j]);
            if (ans > maxans)
                maxans = ans;
            lis.push_back(ans);
        }
        if (caseno > 1)
            printf("\n");
        printf("Test #%d:\n", caseno++);
        printf("  maximum possible interceptions: %d\n", maxans);
    }

    return 0;
}
