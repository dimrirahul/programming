
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


const int MAX_SIZE = 60;
const int NA = -9999;

int g_diffArray[MAX_SIZE][MAX_SIZE];
int g_results[MAX_SIZE][MAX_SIZE];
class PotentialGeometricSequence
{
public:
    void clear() {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                 g_diffArray[i][j] = NA;
                 g_results[i][j] = 0;
            }
        }
    }

    void populateBaseDp(vector <int> &d) {
        for (int i = 0; i < d.size() - 1; i++) {
            g_diffArray[i][i+1] = d[i+1] - d[i];
            g_results[i][i] = 1;
            g_results[i][i+1] = 1;
        }
        g_results[d.size() -1] [d.size() -1] = 1;
    }
    
	int numberOfSubsequences(vector <int> d)
	{
        clear();
        populateBaseDp(d);
        
        if (d.size() == 1) {
            return 1;
        }
        int i = 0; 
        int j = 2;
        int size = d.size();
        int previ, prevj;
        previ = i; prevj = j;
        while(true) {
            if (g_diffArray[i][j-1] != NA && g_diffArray[i+1][j] != NA && g_diffArray[i][j -1 ] == g_diffArray[i+1][j]) {
                g_diffArray[i][j] = g_diffArray[i][j-1];
                g_results[i][j] = 1;
            } else {
                g_diffArray[i][j] = NA;
            }
            i++;
            j++;
            if (j == size) {
                i = 0;
                j = ++prevj;
            }
            if (prevj == size) {
                break;
            }
        }

        //count 
        int sum = 0;
        for (int i = 0; i < d.size(); i++) {
            for (int j = 0; j < d.size(); j++) {
                if (g_results[i][j] == 1) {
                    sum++;
                }
            }
        }
		return sum;
	}
};

