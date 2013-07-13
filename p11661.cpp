#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int L;
string highway;
int r, d;
unsigned min_dist;

int
main()
{
    int i;

    while (cin >> L && L != 0) {
        cin >> highway;

        r = d = -1;
        min_dist = ~0;

        for (i = 0; i < L; i++) {
            switch (highway[i]) {
            case 'R':
                r = i;
                break;
            case 'D':
                d = i;
                break;
            case 'Z':
                r = d = i;
                break;
            }

            if (r != -1 && d != -1 && abs(r - d) < min_dist)
                min_dist = abs(r - d);
        }

        cout << min_dist << endl;
    }

    return 0;
}
