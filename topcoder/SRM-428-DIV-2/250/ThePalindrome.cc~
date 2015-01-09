
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

class ThePalindrome
{
    public:
        bool isPalidrome(string s) {
            REP(i, s.size()/2) {
                if (s[i] != s[s.size()-1 -i]) return false;
            }
            return true;
        }
        int find(string s)
        {

            if (isPalidrome(s)) return s.size();
            int sz = s.size();
            for(int i = (sz +1)/2 ; i < sz; i++) {
                string s1 = s.substr(i - (sz-i));
                if(isPalidrome(s1)) {
                    return 2 * i;
                }
                s1 = s.substr(i+1 - (sz-i));
                if(isPalidrome(s1)) {
                    return 2 * i + 1;
                }
            }
        }
};

