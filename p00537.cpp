#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

enum { P, U, I };

int caseno, num_cases;
string line;
double vals[3];
int hasval[3];

int
find_field(int start)
{
    int i, j, idx, idx2;

    idx = line.find('=', start);

    if (line[idx-1] == 'P')
        i = P;
    else if (line[idx-1] == 'U')
        i = U;
    else if (line[idx-1] == 'I')
        i = I;

    idx2 = line.find_first_of("WVA", idx + 1);
    j = idx2 - (idx+1);
    switch (line[idx2-1]) {
    case 'm':
        vals[i] = 1e-3;
        j--;
        break;
    case 'k':
        vals[i] = 1e3;
        j--;
        break;
    case 'M':
        vals[i] = 1e6;
        j--;
        break;
    default:
        vals[i] = 1.0;
    }

    /*
    printf("foo: %s (%.03lf) [%d] (%c)\n",
        line.substr(idx+1, j).c_str(), vals[i], j, line[idx2-1]);
    */
    vals[i] *= atof(line.substr(idx+1, j).c_str());
    hasval[i] = 1;

    return idx + 1;
}

int
main()
{
    int i, j;

    cin >> num_cases;
    cin.ignore(256, '\n');

    for (caseno = 1; caseno <= num_cases; caseno++) {
        getline(cin, line);

        memset(hasval, 0, sizeof(hasval));

        i = find_field(0);
        find_field(i);

        printf("Problem #%d\n", caseno);
        if (!hasval[P])
            printf("P=%.02lfW\n", vals[U] * vals[I]);
        else if (!hasval[U])
            printf("U=%.02lfV\n", (vals[I] != 0.0) ? vals[P] / vals[I] : 0.0);
        else
            printf("I=%.02lfA\n", (vals[U] != 0.0) ? vals[P] / vals[U] : 0.0);
        putchar('\n');
    }

    return 0;
}
