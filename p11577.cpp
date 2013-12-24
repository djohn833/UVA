#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int caseno, num_cases;
string line;
int maxfreq, counts[26];

int
main()
{
    int i, k;

    cin >> num_cases;
    cin.ignore(256, '\n');

    for (caseno = 1; caseno <= num_cases; caseno++) {
        getline(cin, line);

        maxfreq = 0;
        memset(counts, 0, sizeof(counts));

        for (i = 0; i < line.size(); i++) {
            if (isalpha(line[i])) {
                k = tolower(line[i]) - 'a';
                counts[k]++;
                if (counts[k] > maxfreq)
                    maxfreq = counts[k];
            }
        }

        for (k = 0; k < 26; k++)
            if (counts[k] == maxfreq)
                printf("%c", k + 'a');
        putchar('\n');
    }

    return 0;
}
