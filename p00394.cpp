#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Array {
    int B, elemsize, D, C[11];
};

int N, R;
map<string, Array> arrays;
string s;
Array a;
int addr, L[11], U[11], idx[11];

int
main()
{
    int i, j;
    cin >> N >> R;

    for (i = 0; i < N; i++) {
        cin >> s >> a.B >> a.elemsize >> a.D;

        for (j = 1; j <= a.D; j++)
            cin >> L[j] >> U[j];

        a.C[a.D] = a.elemsize;
        for (j = a.D-1; j > 0; j--)
            a.C[j] = a.C[j+1] * (U[j+1] - L[j+1] + 1);

        a.C[0] = a.B;
        for (j = 1; j <= a.D; j++)
            a.C[0] -= a.C[j] * L[j];

        arrays[s] = a;
    }

    for (i = 0; i < R; i++) {
        cin >> s;
        a = arrays[s];

        for (j = 1; j <= a.D; j++)
            cin >> idx[j];

        addr = a.C[0];
        for (j = 1; j <= a.D; j++)
            addr += a.C[j] * idx[j];

        printf("%s[%d", s.c_str(), idx[1]);
        for (j = 2; j <= a.D; j++)
            printf(", %d", idx[j]);
        printf("] = %d\n", addr);
    }

    return 0;
}
