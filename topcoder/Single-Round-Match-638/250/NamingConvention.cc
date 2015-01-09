
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

class NamingConvention
{
public:
	string toCamelCase(string variableName)
	{
        string res;
        bool underscore = false;
        for (int i = 0; i < variableName.size(); i++) {
            if (underscore) {
                underscore = false;
                res += variableName[i] + 'A' -'a';
            } else {
                if (variableName[i] != '_') {
                    res += variableName[i];
                } else {
                    underscore = true;
                }
            }
        }
		return res;
	}
};

