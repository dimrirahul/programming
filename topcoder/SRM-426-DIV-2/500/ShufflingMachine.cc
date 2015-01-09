
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
#include <string.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

const int MAX_CARDS = 50;

class Comp {
    public:
        bool operator()(int lhs, int rhs) {
            return rhs < lhs;
        }
};
class ShufflingMachine
{
public:
    int occ[MAX_CARDS];
	double stackDeck(vector <int> shuffle, int maxShuffles, vector <int> cardsReceived, int K)
	{
        vector <int> cards;
        memset(occ, 0, MAX_CARDS * sizeof(int));
        REP(i, shuffle.size()) { 
            int pos = i;
            REP(j,  maxShuffles) {
                pos = shuffle[pos];
                REP(k, cardsReceived.size()) { 
                    if(cardsReceived[k] == pos) { occ[i]++; }
                }
            }
        }
        Comp comp;
        sort(occ, occ + MAX_CARDS, comp);
        double s = 0;
        REP(i, K) { s += occ[i]; }
        return s/maxShuffles; 
	}
};

