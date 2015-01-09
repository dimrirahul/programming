
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

class SRMCards
{
public:
	int maxTurns(vector <int> cards)
	{
        sort(cards.begin(), cards.end());
        int start = 0; 
        int count = 0;
        if (cards.size() == 2) {
           if (cards[1] - cards[0] == 1) {
              return 1;
           } else {
              return 2;
           }
        }
        if (cards.size() == 1) {
           return 1;
        } 
        while (start < cards.size() -1 ) {
            if (cards[start + 1] - cards[start] == 1) {
                start += 2;
            } else {
                start += 1;
            }
            count++;
        }
        if (start == cards.size() - 1) {
            count++;
        }
		return count;
	}
};

