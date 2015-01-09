
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

class MagicSpell
{
public:
	string fixTheSpell(string spell)
	{
        string s;
        REP(i, spell.size()) {
            if (spell[i] == 'A' || spell[i] == 'Z') s.push_back(spell[i]);
        }
        int pos = 0;
        for (int i = spell.size()-1; i >= 0; i--) {
            if (spell[i] == 'A' || spell[i] == 'Z') {
                spell[i] = s[pos++];
            } 
        }
		return spell;
	}
};

