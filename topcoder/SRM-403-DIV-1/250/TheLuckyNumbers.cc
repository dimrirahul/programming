

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

typedef long long UI;
class TheLuckyNumbers
{
public:
    UI getIntvalue(string s) {
        UI res = 0;
        REP(i, s.size()) {
            res = res * 10 + s[i] - '0';
        }
        return res;
    }
    int getLucky(int a, int b) {
        int count = 0;
        vector<string> res;
        res.push_back("4");
        res.push_back("7");

        vector<string> f = res;
        vector<string> prev = res;


        for (int i = 0; i < 9; i++) {
            vector <string> curr;
            for (int j = 0; j < prev.size(); j++) {
                for(int k = 0; k < 2; k++) {
                    string s = prev[j] + f[k];
                    curr.push_back(s);
                }
            }

            res.insert(res.end(), curr.begin(), curr.end());
            prev.clear();
            prev.insert(prev.end(), curr.begin(), curr.end());
        }

        REP(i, res.size()) {
            UI value = getIntvalue(res[i]);
            if (value >= (UI)a && value <= (UI)b) {
                count++;
            }
        }

        /*
        REP(i, res.size()) {
            cout << res[i] << "\n";
        }
        */
        return count;
    }


	int count(int a, int b)
	{
        return getLucky(a, b);
	}
};
