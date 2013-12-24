#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int caseno;
string line;
string word[4];
int idx[4], off[2], len[2];

int pos_in_line;

void
pad_to_len(int n)
{
    while (pos_in_line++ <= n)
        cout << " ";
}

int
main()
{
    int i;
    caseno = 1;

    while (getline(cin, line) && line != "#") {
        if (caseno > 1)
            putchar('\n');

        stringstream in(line);
        in >> word[0] >> word[1] >> word[2] >> word[3];

        idx[0] = word[0].find_first_of(word[1]);
        idx[1] = word[1].find_first_of(word[0][idx[0]]);
        idx[2] = word[2].find_first_of(word[3]);
        idx[3] = word[3].find_first_of(word[2][idx[2]]);

        for (i = 0; i < 4; i++) {
            if (idx[i] == string::npos) {
                cout << "Unable to make two crosses\n";
                goto continue_outer;
            }
            //cout << word[i].substr(0, idx[i]) << "[" << word[i].substr(idx[i], 1) << "]" << word[i].substr(idx[i] + 1) << "\n";
        }

        //cout << idx[1] << " " << idx[3] << "\n";

        if (idx[1] > idx[3]) {
            off[0] = 0;
            off[1] = idx[1] - idx[3];
            len[0] = idx[1];
        } else {
            off[0] = idx[3] - idx[1];
            off[1] = 0;
            len[0] = idx[3];
        }

/*
        cout << "offsets: " << off[0] << " " << off[1] << "\n";
        cout << "end lens: "
             << (word[1].size() - idx[1] + off[0]) << " "
             << (word[3].size() - idx[3] + off[1]) << "\n";
        cout << "end lens: "
             << word[1].size() - idx[1] - 1 << " "
             << word[3].size() - idx[3] - 1 << "\n";
*/

        if (word[1].size() - idx[1] - 1 > word[3].size() - idx[3] - 1) {
            len[1] = word[1].size() - idx[1] - 1;
        } else {
            len[1] = word[3].size() - idx[3] - 1;
        }

        //cout << idx[0] << " " << idx[2] << "\n";

        for (i = 0; i < len[0]; i++) {
            pos_in_line = 1;
            if (i >= off[0]) {
                pad_to_len(idx[0]);
                cout << word[1][i - off[0]];
            }
            if (i >= off[1]) {
                pad_to_len(word[0].size() + 3 + idx[2]);
                cout << word[3][i - off[1]];
            }
            cout << "\n";
        }

        cout << word[0] << "   " << word[2] << "\n";

        for (i = 0; i < len[1]; i++) {
            pos_in_line = 1;
            if (i + idx[1] + 1 < word[1].size()) {
                pad_to_len(idx[0]);
                cout << word[1][i + idx[1] + 1];
            }
            if (i + idx[3] + 1 < word[3].size()) {
                pad_to_len(word[0].size() + 3 + idx[2]);
                cout << word[3][i + idx[3] + 1];
            }
            cout << "\n";
        }

continue_outer:
        caseno++;
    }

    return 0;
}
