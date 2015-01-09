
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

typedef pair<int, int> PI;
typedef map< PI, int > MI;
typedef queue< PI> QI;
typedef set< PI > SI;
const int GRID_SIZE = 401;
class CandyShop
{
public:

    int m_grid[GRID_SIZE][GRID_SIZE];

    void updateGrid(int x, int y, int d) {
        x += 200;
        y += 200;
        for (int i = x - d; i <= x + d; i++) {
            for (int j = y - d; j <= y + d; j++) {
                if ( abs(x - i) + abs(y - j) <= d) {
                    m_grid[i][j]++;
                }
            }
        }
    }

	int countProbablePlaces(vector <int> X, vector <int> Y, vector <int> R)
	{

        for (int i = 0; i < X.size(); i++) {
            updateGrid(X[i], Y[i], R[i]);
        }
        int count = 0;
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (m_grid[i][j] ==  X.size()) {
                    count++;
                }
            }
        }

        
        
        return count;
	}
};

