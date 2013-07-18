#include <cstdio>
#include <iostream>
#include <climits>
#include <sstream>
#include <string>
using namespace std;

int caseno;
string line;
int maxprod, curmax, curmin;

int
max(int a, int b)
{
    return (a > b) ? a : b;
}

int
min(int a, int b)
{
    return (a < b) ? a : b;
}

int
main()
{
    int i;
    caseno = 1;

    while (getline(cin, line)) {
        /*
        if (caseno > 1)
            putchar('\n');
        //*/

        stringstream in(line);

        maxprod = INT_MIN;
        curmax = curmin = 1;

        while (in >> i && i != -999999) {
            if (i == 0)
                curmax = curmin = 1;
            else if (i > 0) {
                curmax = max(curmax * i, i);
                curmin = min(curmin * i, i);
            } else {
                curmax = max(curmin * i, i);
                curmin = min(curmin * i, i);
            }

            maxprod = max(maxprod, curmax);
        }

        printf("%d\n", maxprod);
        caseno++;
    }

    return 0;
}
