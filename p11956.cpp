#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int caseno, num_cases;
string line;
unsigned char mem[100];
int p;

int
main()
{
    int i;
    cin >> num_cases;
    cin.ignore(256, '\n');

    for (caseno = 1; caseno <= num_cases; caseno++) {
        getline(cin, line);

        memset(mem, 0, sizeof(mem));
        p = 0;

        printf("Case %d:", caseno);
        for (i = 0; i < line.size(); i++) {
            switch (line[i]) {
            case '>':
                p = (p + 1) % 100;
                break;
            case '<':
                p = (p - 1 + 100) % 100;
                break;
            case '+':
                mem[p]++;
                break;
            case '-':
                mem[p]--;
                break;
            case '.':
                //printf(" %02X", mem[p]);
                break;
            }
        }

        for (i = 0; i < 100; i++)
            printf(" %02X", mem[i]);
        putchar('\n');
    }

    return 0;
}
