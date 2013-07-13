#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int caseno = 1;
vector<int> vals, lis;
int ans, maxans, end;

void
print_seq(int i, int n)
{
    int j;

    for (j = i - 1; j >= 0; j--) {
        if (lis[j] == n-1 && vals[j] < vals[i]) {
            print_seq(j, n - 1);
            break;
        }
    }

    printf("%d\n", vals[i]);
}

int
main()
{
    int i, j, k;

    i = end = 0;
    maxans = 1;
    while (cin >> k) {
        vals.push_back(k);
        ans = 1;
        for (j = 0; j < i; j++)
            if (vals[i] > vals[j])
                ans = max(ans, 1 + lis[j]);
        if (ans >= maxans) {
            maxans = ans;
            end = i;
        }
        lis.push_back(ans);
        i++;
    }

    printf("%d\n-\n", maxans);
    print_seq(end, maxans);

    return 0;
}
