#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string line, word;

int
main()
{
    while (getline(cin, line) && line != "*") {
        stringstream in(line);
        char c;
        bool same = true;
        in >> word;
        c = tolower(word[0]);

        while (in >> word)
            same &= c == tolower(word[0]);

        cout << (same ? "Y" : "N") << endl;
    }

    return 0;
}
