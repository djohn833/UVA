#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string line;
int caseno;

int
main()
{
    caseno = 1;

    while (getline(cin, line) && line != "*") {
        if (line == "Hajj")
            printf("Case %d: Hajj-e-Akbar\n", caseno++);
        else if (line == "Umrah")
            printf("Case %d: Hajj-e-Asghar\n", caseno++);
    }

    return 0;
}
