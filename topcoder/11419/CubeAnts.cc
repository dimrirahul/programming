
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

class CubeAnts
{
public:
	int getMinimumSteps(vector <int> pos)
	{
        int d =0;
        for (int i = 0 ; i < pos.size(); i++) {
            int tp = pos[i];
            int td = 0;
            if (tp == 1 || tp == 3 || tp == 4 ) {
                td = 1;
            } else if ( tp == 5 || tp == 2 || tp == 7) {
                td = 2;
            } else if (tp == 6) {
                td = 3;
            } 
            
            d = max(d, td);
        }
		return d;
	}
};

