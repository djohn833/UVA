#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int caseno, num_cases;
string line, piece;

int
main()
{
    int m, f, n;
    cin >> num_cases;
    cin.ignore(256, '\n');

    for (caseno = 1; caseno <= num_cases; caseno++) {
        getline(cin, line);
        stringstream in(line);

        m = f = n = 0;

        while (in >> piece) {
            if (piece == "MM")
                m++;
            else if (piece == "FF")
                f++;
            n++;
        }

        cout << (n > 1 && m == f ? "LOOP\n" : "NO LOOP\n");
    }

    return 0;
}
