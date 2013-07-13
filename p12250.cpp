#include <iostream>
#include <string>
using namespace std;

string line, trans;
int caseno;

int
main()
{
    caseno = 1;
    while (getline(cin, line) && line != "#") {
        if (line == "HELLO")
            trans = "ENGLISH";
        else if (line == "HOLA")
            trans = "SPANISH";
        else if (line == "HALLO")
            trans = "GERMAN";
        else if (line == "BONJOUR")
            trans = "FRENCH";
        else if (line == "CIAO")
            trans = "ITALIAN";
        else if (line == "ZDRAVSTVUJTE")
            trans = "RUSSIAN";
        else
            trans = "UNKNOWN";

        cout << "Case " << caseno++ << ": " << trans << endl;
    }
    return 0;
}
