#include <iostream>
#include <string>
using namespace std;

int caseno, num_cases;

char one[] = "one", two[] = "two";
string line;
int one_wrong, two_wrong;

int
main()
{
    int i;

    cin >> num_cases;
    cin.ignore(256, '\n');

    for (caseno = 1; caseno <= num_cases; caseno++) {
        getline(cin, line);
        if (line.size() == 5)
            cout << 3 << endl;
        else {
            one_wrong = two_wrong = 0;

            for (i = 0; i < 3; i++) {
                if (line[i] != one[i])
                    one_wrong++;
                if (line[i] != two[i])
                    two_wrong++;
            }

            if (one_wrong <= 1)
                cout << 1 << endl;
            else if (two_wrong <= 1)
                cout << 2 << endl;
        }
    }

    return 0;
}
