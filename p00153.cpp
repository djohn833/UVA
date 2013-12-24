#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int caseno;
string line;

struct Chars {
    int counts[26];
};

int
main()
{
    caseno = 1;

    while (getline(cin, line) && line != "#") {
        Chars c;
        int i;

        for (i = 0; i < line.size(); i++)
            c.counts[line[i]]++;



        caseno++;
    }

    return 0;
}
