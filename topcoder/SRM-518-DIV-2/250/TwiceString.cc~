
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

class TwiceString
{
public:
    int findPrefixLen(string& s) {
        int res = s.size();
        int len = s.size() -1;
        while(len > 0) {
            bool match = (s.substr(s.size() - len, len) == s.substr(0, len));
            if (match) {
                res = len;
                break;
            }
            len--;
        }
        return res;
    }
	string getShortest(string s)
	{
        int len = findPrefixLen(s);
        if (len == s.size()) {
            return  s+s;
        } else {
            string temp = s;
            for(int i = len; i < s.size(); i++) {
                temp.push_back(s[i]);
            }
            return temp;
        }
	}
};

