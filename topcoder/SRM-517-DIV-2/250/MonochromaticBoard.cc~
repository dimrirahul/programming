
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


const int MAX = 51;
bool g_visited[MAX][MAX];
class MonochromaticBoard
{
public:
    vector<string> vs;
    int maxX, maxY;
    char getChar(int x, int y) {
        return vs[x][y];
    }
    void fillVisited() {
        REP(i, MAX) {
            REP(j, MAX) {
                g_visited[i][j] = false;
            }
        }
    }

    bool isRowBlack(int x, int y) {
        for (int i = 0; i < maxY; i++) {
            if (getChar(x, i) != 'B') {
                return false;
            }
        }
        return true;
    }
    bool isColBlack(int x, int y) {
        for (int i = 0; i < maxX; i++) {
            if (getChar(i, y) != 'B') {
                return false;
            }
        }
        return true;
    }

    void fillRow(int x, int y) {
        REP(i, maxY) {
            g_visited[x][i] = true;
        }
    }

    void fillCol(int x, int y) {
        REP(i, maxX) {
            g_visited[i][y] = true;
        }
    }
	int theMin(vector <string> board)
	{
        vs = board;
        int moves = 0;
        maxX = board.size();
        maxY = board[0].size();
        REP(i, maxX) {
            REP(j, maxY) {
                if (getChar(i, j) == 'W' || g_visited[i][j]) { 
                    continue;
                }
                bool rowBlack = isRowBlack(i, j);
                bool colBlack = isColBlack(i, j);

                if (rowBlack && colBlack) {
                    moves++;
                    if (maxX > maxY) {
                        fillCol(i, j);
                    } else {
                        fillRow(i, j);
                    }
                } else if (rowBlack) {
                    moves++;
                    fillRow(i, j);
                } else if (colBlack) {
                    moves++;
                    fillCol(i, j);
                }
            }
        }

		return moves; 
	}
};

