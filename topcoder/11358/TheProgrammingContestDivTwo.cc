
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

class TheProgrammingContestDivTwo
{
public:
	vector <int> find(int T, vector <int> requiredTime)
	{

        sort(requiredTime.begin(), requiredTime.end());
        int totTime = 0; int solved = 0; int penalty = 0;
        for (int i  = 0 ; i < requiredTime.size(); i++) {
            if (totTime + requiredTime[i] <= T) {
                totTime += requiredTime[i];
                solved++;
                penalty += totTime;
            }else {
                break;
            }
        }

        vector<int> out;
        out.push_back(solved);
        out.push_back(penalty);
		return out; 
	}
};

