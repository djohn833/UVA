#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int caseno;
string str;
string rules[10][2];
int num_rules;

int
main()
{
    int i, pos;
    caseno = 1;

    while (cin >> num_rules && num_rules != 0) {
        cin.ignore(256, '\n');

        for (i = 0; i < num_rules; i++) {
            getline(cin, rules[i][0]);
            getline(cin, rules[i][1]);
        }

        getline(cin, str);

        for (i = 0; i < num_rules; i++) {
            for (;;) {
                pos = str.find(rules[i][0]);
                if (pos == string::npos)
                    break;
                str.replace(pos, rules[i][0].size(), rules[i][1]);
            }
        }

        cout << str << "\n";

        caseno++;
    }

    return 0;
}
