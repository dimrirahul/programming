
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

const int INF = 1000;
class AllCycleLengths
{
public:
    vector <string> arcs;
    vector <string> cycleLengths;

    void populateCycleLengths() {
        int numNodes = arcs[0].size();
        REP (i, numNodes) {
            set <int> curr, next;
            curr.insert(i);
            int days = 0;
            string res;
            while (days < INF) {
                for (set<int>::const_iterator it = curr.begin(); it != curr.end(); it++) {
                    for (int j = 0; j < numNodes; j++) {
                        if (arcs[*it][j] == 'Y') next.insert(j);
                    }
                }

                if (next.count(i) > 0) res += '1';
                else res += '0';

                days++;
                curr.clear();
                curr.insert(ALL(next));
                next.clear();
            }
            cycleLengths.push_back(res);
        }
    }
    void printCycleLengths() {
        REP (i, cycleLengths.size()) {
            cout << cycleLengths[i] << "\n";
        }
        cout << "\n";
    }
    string mergeCycleLengths() {
        string res;
        REP (i, INF) {
            bool found = false;
            REP (j, cycleLengths.size()) {
                if (cycleLengths[j][i] == '1') {
                    found = true;
                    break;
                }
            }
            if (found) res += '1';
            else res += '0';
        }

        //cout << "Res = " << res << "\n";
        for (int i = 0; i <= INF; i++) {
            for (int j = 1; j < 31; j++) {
                string s = res.substr(0, i);
                string t = res.substr(i, j);
                while (t.size() < INF) {
                    t += t;
                }
                s += t;
                s = s.substr(0, INF);
                //cout << "S   = " << s << "\n";
                if (res == s) {
                    s = res.substr(0, i) + '(' + res.substr(i, j) + ')';
                    return s;
                }
            }
        }
        return res;

    }
	string findAll(vector <string> _arcs)
	{
        arcs = _arcs;
        populateCycleLengths();
        //printCycleLengths();
        return mergeCycleLengths(); 
	}
};

