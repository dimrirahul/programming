
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

class CreateGroups
{
public:
	int minChanges(vector <int> groups, int minSize, int maxSize)
	{
        int  defNeed, canGive, defGive, canTake;
        defNeed = canGive = defGive = canTake = 0;
        int size = groups.size();
        REP(i, size) {
            if (groups[i] < minSize) {
                defNeed += (minSize - groups[i]);
                canTake += (maxSize - groups[i]);
            } else if ( minSize <= groups[i] && maxSize >= groups[i])  {
                canGive += (groups[i] - minSize);
                canTake += (maxSize - groups[i]);
            } else if ( groups[i] > maxSize) { 
                defGive += (groups[i] - maxSize);
                canGive += (groups[i] - minSize);
            }
        }

        if ( defNeed > canGive || defGive > canTake ) return -1;
        return max(defNeed, defGive);
	}
};

