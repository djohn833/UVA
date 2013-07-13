#include <iostream>
#include <string>
using namespace std;

int n;
string names[100];
char *words[] = {
    "Happy", "birthday", "to", "you",
    "Happy", "birthday", "to", "you",
    "Happy", "birthday", "to", "Rujia",
    "Happy", "birthday", "to", "you"
};

int
main()
{
    int i, j;
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> names[i];

    for (i = 0; i < n; ) {
        for (j = 0; j < 16; i++, j++) {
            cout << names[i % n] << ": " << words[j] << endl;
        }
    }

    return 0;
}
