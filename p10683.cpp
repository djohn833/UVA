#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string t;
int h, m, s, c;

int
digits(int i, int n)
{
    return atoi(t.substr(i, n).c_str());
}

int
main()
{
    long long time;

    while (cin >> t) {
        h = digits(0, 1);
        m = digits(1, 2);
        s = digits(3, 2);
        c = digits(5, 2);

        time = h;
        time = time * 60 + m;
        time = time * 60 + s;
        time = time * 60 + c;
        cout << "foo " << time << endl;

        stringstream out;
        out << (time * 10000000) / (24*60*60*100);
        cout << out.str().substr(0, 7).c_str() << endl;
    }

    return 0;
}
