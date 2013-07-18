#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int caseno, num_cases;
string line, line2;

int
main()
{
    int i, j, k, l, m;
    cin >> num_cases;
    cin.ignore(256, '\n');

    for (caseno = 1; caseno <= num_cases; caseno++) {
        getline(cin, line);
        getline(cin, line2);

        i = line.find('<');
        j = line.find('>', i+1);
        k = line.find('<', j+1);
        l = line.find('>', k+1);
        m = line2.find("...");

        cout << line.substr(0, i)
            << line.substr(i+1, j-i-1)
            << line.substr(j+1, k-j-1)
            << line.substr(k+1, l-k-1)
            << line.substr(l+1) << endl;
        cout << line2.substr(0, m)
            << line.substr(k+1, l-k-1)
            << line.substr(j+1, k-j-1)
            << line.substr(i+1, j-i-1)
            << line.substr(l+1) << endl;
    }

    return 0;
}
