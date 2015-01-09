
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

class TaroGrid
{
public:

    int getMaxConsecutive(vector<string>& grid, int col) {

        int maxCount;
        int prevColor;
        maxCount = 1;
        if (grid[0][col] == 'W') {
            prevColor = 'W';
        } else {
            prevColor = 'B';
        }

        int count = 1;
        for(int i = 1; i < grid.size(); i++) {
            cout << "Got = " << grid[i][col] << " Previous = " << (char) prevColor << "\n";
            if (grid[i][col] == prevColor) {
                count++;
                cout << " Match incrementing count \n";
            } else {
                maxCount = max(maxCount, count);
                count = 1;
                prevColor = grid[i][col];
                cout << " No Match resetting count \n";
            }

            if ( i == grid.size() -1) {
                maxCount = max(maxCount, count);
            }
        }
        cout << "returning maxCount = " << maxCount << "\n";
        return maxCount;

    }
	int getNumber(vector <string> grid)
	{
		int colMax = 1;
        for (int i = 0; i < grid.size(); i++) {
            colMax = max (colMax, getMaxConsecutive(grid, i));
        }
       return colMax; 
	}
};

