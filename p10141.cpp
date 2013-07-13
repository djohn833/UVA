#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct Prop {
    string name;
    double d;
    int r;
};

bool prop_sort(const Prop& lhs, const Prop& rhs)
{
    return (lhs.r > rhs.r) || (lhs.r == rhs.r && lhs.d < rhs.d);
}

int caseno;
int n, p;
Prop props[1000];
string line;

int
main()
{
    int i, j;
    caseno = 1;

    while (cin >> n >> p && !(n == 0 && p == 0)) {
        for (i = 0; i < n + 1; i++)
            cin.ignore(256, '\n');

        for (i = 0; i < p; i++) {
            getline(cin, props[i].name);
            cin >> props[i].d >> props[i].r;

            for (j = 0; j < props[i].r + 1; j++)
                cin.ignore(256, '\n');
        }

        sort(props, props + p, prop_sort);

        if (caseno > 1)
            cout << endl;
        cout << "RFP #" << caseno++ << endl;
        cout << props[0].name << endl;
    }

    return 0;
}
