

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

const bool dbg = !true;
class InfiniteString
{
    public:
        bool isPrefixPattern(string s, int len) {
            string s1 = s.substr(0, len);
            if (dbg) cout << "S1 for string " << s << " And len = " << len << " = " << s1 << "\n";
            if (s.size() % s1.size() != 0) return false;
            int d = s.size() / s1.size();
            string s2;
            REP(i, d) {
                s2 += s1;
            }
            return s2 == s;
        }

        string minPrefixPat(string s) {
            for (int i = 1; i <= s.size(); i++) {
                if (isPrefixPattern(s, i)) {
                    return s.substr(0, i);
                }
            }
            return s;
        }
        string equal(string s, string t)
        {
            return minPrefixPat(s) == minPrefixPat(t) ? string("Equal"): string("Not equal");
        }
};

