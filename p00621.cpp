#include <iostream>
#include <string>
using namespace std;

int caseno, num_cases;
string line;

int
main()
{
    cin >> num_cases;
    cin.ignore(256, '\n');

    for (caseno = 1; caseno <= num_cases; caseno++) {
        getline(cin, line);

        if (line == "1" || line == "4" || line == "78")
            cout << "+\n";
        else if (line.substr(line.size() - 2, 2) == "35")
            cout << "-\n";
        else if (line[0] == '9' && line[line.size() - 1] == '4')
            cout << "*\n";
        else
            cout << "?\n";
    }

    return 0;
}
