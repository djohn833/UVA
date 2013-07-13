#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long Num;

int caseno, num_cases;
string S, perm;
Num N, fact[21];


int
main()
{
    int i, k;
    cin >> num_cases;

    fact[0] = 1;
    for (i = 1; i <= 20; i++)
        fact[i] = i * fact[i-1];

    for (caseno = 1; caseno <= num_cases; caseno++) {
        cin >> S >> N;

        perm.clear();
        sort(S.begin(), S.end());

        for (i = S.size(); i > 0; i--) {
            k = N / fact[i-1];
            perm += S[k];
            S.erase(k, 1);
            N = N % fact[i-1];
        }

        cout << perm << endl;
    }

    return 0;
}
