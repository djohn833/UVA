#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int caseno, num_cases;
string line, word;

int
main()
{
    int i;

    cin >> num_cases;
    cin.ignore(256, '\n');
    cin.ignore(256, '\n');

    for (caseno = 1; caseno <= num_cases; caseno++) {
        if (caseno > 1)
            putchar('\n');

        printf("Case #%d:\n", caseno);

        while (getline(cin, line) && line != "") {
            stringstream in(line);
            i = 1;

            while (in >> word) {
                if (i <= word.size()) {
                    cout << word[i-1];
                    i++;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
