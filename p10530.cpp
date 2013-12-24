#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int caseno;
string response;
int guess;
int min_guess, max_guess;
int is_lying;

void
init(void)
{
    min_guess = 11;
    max_guess = 0;
    is_lying = 0;
}

int
main()
{
    caseno = 1;

    init();
    while (cin >> guess && guess != 0) {
        cin.ignore(256, '\n');
        getline(cin, response);

        if (response == "right on") {
            if (!(min_guess < guess && guess < max_guess))
                is_lying = 1;

            if (is_lying)
                printf("Stan is dishonest\n");
            else
                printf("Stan may be honest\n");

            init();
        } else if (response == "too low") {
            if (guess <= min_guess)
                min_guess = guess;
            if (guess >= max_guess)
                is_lying = 1;
        } else if (response == "too high") {
            if (guess >= max_guess)
                max_guess = guess;
            if (guess <= min_guess)
                is_lying = 1;
        }

        caseno++;
    }

    return 0;
}
