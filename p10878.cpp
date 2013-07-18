#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string line;

int
main()
{
    int i;
    unsigned char c;

    while (getline(cin, line)) {
        if (line[0] == '_')
            continue;

        c = '\0';
        for (i = 1; i <= 5; i++)
            if (line[i] == 'o')
                c |= 1 << (8-i);
        for (i = 7; i <= 9; i++)
            if (line[i] == 'o')
                c |= 1 << (9-i);

        printf("%c", c);
    }

    return 0;
}
