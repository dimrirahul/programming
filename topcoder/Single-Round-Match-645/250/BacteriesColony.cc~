
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
const int SZ = 51;
class BacteriesColony
{
public:
    int prev[SZ];
    int next[SZ];
    int elements;
    bool areEqual() {
        for (int i = 0; i < elements; i++) {
            if (prev[i] != next[i]) return false;
        }
        return true;
    }

    void update() {
        for (int i = 0; i < elements; i++) {
            if (i == 0 || i == elements - 1) {
                next[i] = prev[i];
            } else {
                if ((prev[i-1] > prev[i]) && (prev[i+1] > prev[i])) {
                    next[i] = prev[i] +1;
                } else if ((prev[i-1] < prev[i]) && (prev[i+1] < prev[i])) {
                    next[i] = prev[i] -1;
                } else {
                    next[i] = prev[i];
                }
            }
        }
        for (int i = 0; i < elements; i++) {
            int t = prev[i];
            prev[i] = next[i];
            next[i] = t;
        
        }
    }
	vector <int> performTheExperiment(vector <int> colonies)
	{
        elements = colonies.size();
        for (int i = 0; i <elements; i++) {
            prev[i] = colonies[i];
            next[i] = -1;
        }
        while(!areEqual()) {
            update();
        }
        vector <int> res;
        for (int i = 0; i < elements; i++) {
            res.push_back(prev[i]);
        }

		return res;
	}
};

