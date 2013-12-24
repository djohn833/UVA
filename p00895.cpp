#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int caseno;
string line;
int dict[1000][26] = { 0 };
int word[26];

int
main()
{
    int i, j, n, num_matches;
    bool match;

    n = 0;
    while (getline(cin, line) && line != "#") {
        for (j = 0; j < line.size(); j++)
            dict[n][line[j] - 'a']++;
        n++;
    }

    while (getline(cin, line) && line != "#") {
        memset(word, 0, sizeof(word));
        num_matches = 0;

        for (j = 0; j < line.size(); j++)
            if (isalpha(line[j]))
                word[line[j] - 'a']++;

        for (i = 0; i < n; i++) {
            match = true;
            for (j = 0; j < 26; j++)
                if (word[j] < dict[i][j])
                    match = false;
            if (match)
                num_matches++;
        }

        printf("%d\n", num_matches);
    }

    return 0;
}
