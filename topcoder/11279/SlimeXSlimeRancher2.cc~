
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

class SlimeXSlimeRancher2
{
public:
	int train(vector <int> attributes)
	{
        int maxVal = attributes[0];
        for (int i = 1; i< attributes.size(); i++) {
            maxVal = max(maxVal, attributes[i]);
        }

        int sum = 0;
        for (int i = 0; i < attributes.size(); i++) {
            sum += maxVal - attributes[i];
        }


		return sum;
	}
};

