#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string line;
char c;

int
main()
{
    while (getline(cin, line) && line != "DONE") {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        line.erase(remove(line.begin(), line.end(), '.'), line.end());
        line.erase(remove(line.begin(), line.end(), ','), line.end());
        line.erase(remove(line.begin(), line.end(), '!'), line.end());
        line.erase(remove(line.begin(), line.end(), '?'), line.end());

        bool pal = true;
        int n = line.size();
        for (int i = 0; i < n; i++) {
            pal &= (tolower(line[i]) == tolower(line[n - i - 1]));
        }

        if (pal)
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
    }

    return 0;
}
