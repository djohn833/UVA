#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int L;
int wire[100000];
int bend;
string dir;

enum { PX, NX, PY, NY, PZ, NZ };
int rot[][6] = {
    { PX, NX, PY, NY, PZ, NZ },
    { NX, PX, NY, PY, PZ, NZ },
    { PY, NY, NX, PX, PZ, NZ },
    { NY, PY, PX, NX, PZ, NZ },
    { PZ, NZ, PY, NY, NX, PX },
    { NZ, PZ, PY, NY, PX, NX }
};

int
main()
{
    int i, j;

    while (cin >> L && L != 0) {
        memset(wire, 0, sizeof(wire));

        for (i = L-1; i > 0; i--) {
            cin >> dir;

            if (dir == "No")
                continue;
            else if (dir == "+y")
                bend = PY;
            else if (dir == "-y")
                bend = NY;
            else if (dir == "+z")
                bend = PZ;
            else if (dir == "-z")
                bend = NZ;

            for (j = L-1; j >= i; j--)
                wire[j] = rot[bend][wire[j]];
        }

        switch (wire[L-1]) {
        case PX:
            cout << "+x\n";
            break;
        case NX:
            cout << "-x\n";
            break;
        case PY:
            cout << "+y\n";
            break;
        case NY:
            cout << "-y\n";
            break;
        case PZ:
            cout << "+z\n";
            break;
        case NZ:
            cout << "-z\n";
            break;
        }
    }

    return 0;
}
