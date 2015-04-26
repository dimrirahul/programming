
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

class RobotOnMoonEasy
{
public:
        vector<string> v;
        int R; int C;
        bool valid(int r, int c) {
            return (r < R && r >= 0 && c < C && c >= 0);
        }
        bool isAlive(int& r, int& c, int d) {
            if ( d == 'U') {
                if (!valid(r - 1, c)) return false;
                if (v[r -1][c] != '#') r--;
            } else if ( d == 'D') {
                if (!valid(r + 1, c)) return false;
                if (v[r+1][c] != '#') r++;
            } else if (d == 'R') {
                if (!valid(r, c+1)) return false;
                if (v[r][c+1] != '#') c++;
            } else {
                if (!valid(r, c-1)) return false;
                if (v[r][c-1] != '#') c--;
            }
            return true;
        }
                
	string isSafeCommand(vector <string> board, string S)
	{
                v = board;
                R = board.size();
                C = board[0].size();
                int r = -1, c = -1;
                REP (i, board.size()) {
                    REP (j, board[i].size()) {
                        if (board[i][j] == 'S') {
                            r = i;
                            c = j;
                        }
                    }
                }
                bool alive = true;
                REP (i, S.size()) {
                    if (!isAlive(r, c, S[i])) {
                        alive = false;
                        break;
                    }
                }

		return (alive ? string("Alive"): string("Dead"));
	}
};

