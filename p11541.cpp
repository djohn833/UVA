#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int caseno, num_cases;
string line, out;

int
main()
{
    int i, j, k, n;

    cin >> num_cases;
    cin.ignore(256, '\n');

    for (caseno = 1; caseno <= num_cases; caseno++) {
        getline(cin, line);
        out.clear();

        i = 0;

        while (i < line.size()) {
            j = line.find_first_of(alpha, i+1);

            if (j == string::npos)
                j = line.size();

            n = 0;
            for (k = i+1; k < j; k++)
                n = 10*n + (line[k] - '0');

            out.append(n, line[i]);
            i = j;
        }

        printf("Case %d: %s\n", caseno, out.c_str());
    }

    return 0;
}
