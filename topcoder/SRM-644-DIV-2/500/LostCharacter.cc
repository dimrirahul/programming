
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

class Wrap {
    public:
        string s;
        int pos;
        Wrap(string s1, int p) {
            s = s1;
        }

        string prefix() {
            return s.substr(0, pos);
        }

        string suffix() {
            return s.substr(pos+1);
        }

        bool operator < (Wrap other) {
            if (pos != other.pos) {
                return pos < other.pos;
            } else if ( prefix() < other.prefix() ) {
                return prefix() < other.prefix();
            } else {
                return suffix() < other.suffix();
            }
        }
};
class LostCharacter
{
public:
    map <string, int> posByString;
    vector <Wrap> wv;
    vector <string> vs;

    int findQ(string s) {
        int i = 0;
        bool found = false;
        while ( i < s.size() ) {
            if (s[i] == '?') {
                found = true;
                break;
            } else {
                i++;
            }
        }
        if (found) return i;
        else return -1;
    }
	vector <int> getmins(vector <string> str)
	{
        int pos = 0;
		for (int i = 0; i < str.size(); i++) {
            int p = findQ(str[i]);
            if (p != -1) {
                wv.push_back(Wrap(str[i], p));
            } else {
                vs.push_back(str[i]);
                posByString[str[i]] = pos++;
            }
        }

        sort(ALL(wv));
        sort(ALL(vs));
	}
};

