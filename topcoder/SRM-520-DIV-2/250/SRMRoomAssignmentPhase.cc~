
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

    bool cmp(int a, int b) {
        return a > b;
    }
class SRMRoomAssignmentPhase
{
public:

	int countCompetitors(vector <int> ratings, int K)
	{
        int m = ratings[0];
        sort(ratings.begin(), ratings.end(), cmp);
        int i = 0;
        for(;; i++) {
            if (ratings[i] == m) {
               break;
            }
        } 
        return (i)/K;
	}
};

