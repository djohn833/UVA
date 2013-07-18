#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Rec {
    string seq, acct, amount;
} rec;

string line, acctnum, acctname, seq, amount, prevseq;
map<string, string> accounts;
vector<Rec> trans;
long long bal;

int
main()
{
    int i;

    while (getline(cin, line)) {
        acctnum = line.substr(0, 3);
        acctname = line.substr(3);
        if (acctnum == "000")
            break;
        accounts[acctnum] = acctname;
    }

    bal = 0;
    while (getline(cin, line)) {
        rec.seq = line.substr(0, 3);
        rec.acct = line.substr(3, 3);
        rec.amount = line.substr(6);
        while (rec.amount[0] == ' ')
            rec.amount.erase(0, 1);

        if (rec.seq != prevseq) {
            if (bal != 0) {
                printf("*** Transaction %s is out of balance ***\n",
                    rec.seq.c_str());
                for (i = 0; i < trans.size(); i++) {
                    printf("%s %-30s % 7s.%2s\n",
                        trans[i].acct.c_str(),
                        accounts[trans[i].acct].c_str(),
                        trans[i].amount.substr(0, trans[i].amount.size() - 2).c_str(),
                        trans[i].amount.substr(trans[i].amount.size() - 2, 2).c_str());
                }
                printf("%s %-30s % 7d.%02d\n",
                    "999", "Out of Balance", bal / 100, bal % 100);
            }

            bal = 0;
            trans.clear();
        }

        if (rec.seq == "000")
            break;

        bal -= atoi(rec.amount.c_str());
        trans.push_back(rec);
        prevseq = rec.seq;
    }

    return 0;
}
