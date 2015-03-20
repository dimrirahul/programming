
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

class TaroFillingAStringDiv2
{
    public:
        int getUgliness(string str) {
            int res = 0;
            int s = str.size();
            for (int k = 1; k <= s; k++) {
                for (int i = 0; i +  2 * k <= s; i++) {
                    if (str.substr(i, k) == str.substr(i + k, k)) res++;
                }
            }
            cout << "Res =" << res << " for  str=" << str << "\n";
            return res;
        }
        int getMatch(string str) {
            for (int i = 0; i < str.size() ; i++) {
                for (int k = 1; i + 2 * k <= str.size(); k++) {
                    if (str.substr(i, k) == str.substr(i + k, k)) return i + k;
                }
            }
            return -1;
        }
        int getNumber(string s)
        {
            string res;
            REP (i, s.size()) {
                if (s[i] != '?') res += s[i];
                else {
                    int p = getMatch(res);
                    cout << "p =" << p << " for  str=" << res << "\n";
                    if (p == -1) {
                        if (res.size() == 0) res += 'A';
                        else {
                            if (res[res.size() - 1] == 'A') {
                                res += 'B';
                            } else {
                                res += 'A';
                            }
                        }
                    } else {
                        if (res[p] == 'B') {
                            res += 'A';
                        } else {
                            res += 'B';
                        }
                    }
                }
            }
            cout << res << "\n";
            return getUgliness(res);
        }
};

