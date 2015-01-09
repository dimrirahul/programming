
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
const int MATRIX_SIZE = 5;
typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector < VI > VVI;
class PiecesMover
{
public:
    int masks[6]; // 5 checks the first bits of all numbers;
    
    void initMasks() {
        REP(i, 6) { masks[i] = 0; }
        for (int i = 0; i < 25; i++) {
            if (i < 5) {
                masks[4] = masks[4] | (1 << i);
            } else if (i < 10) {
                masks[3] = masks[3] | (1 << i);
            } else if (i < 15) {
                masks[2] = masks[2] | (1 << i);
            } else if (i < 20) {
                masks[1] = masks[1] | (1 << i);
            } else if (i < 25) {
                masks[0] = masks[0] | (1 << i);
            }

            if (i == 20 || i == 15 || i == 10 || i == 5 || i == 0) {
                masks[5] = masks[5] | (1 << i);
            }
        }
    }

    int convertBoardToNumber(vector <string> & board) {
        int res = 0;
        for (int i = 0; i < board.size(); i++) {
            int num = 0;
            for(int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '*') {
                    num = num | (1 << j);
                }
            }
            res = res << board[i].size();
            res = res | num;
        }
        return res;
    }

    int normalize(int n) {
        while((n & masks[0]) == 0) {
            n = n << MATRIX_SIZE;
        }
        while ((n & masks[5]) == 0) {
            int t = 0;
            int f[5];
            REP(i, 5) {
                f[i] = masks[i] & n;
                f[i] = f[i]/2;
                t = t | f[i];
            }
            n = t;
        }
        return n;
    }
    
    void printMasks() {
        REP(i, 6) {
            bitset<32> b(masks[i]);
            printf("index = %d, value=%s\n", i, b.to_string().c_str());
        }
    }
    int getMinimumMoves(vector <string> board)
    {
        initMasks();
        printMasks();
        vector<string> vi;
        vi.push_back(string("..*.."));
        vi.push_back(string("..*.."));
        vi.push_back(string(".*..."));
        vi.push_back(string("....."));
        vi.push_back(string("....."));

        vector<string> vj;
        vj.push_back(string("....."));
        vj.push_back(string(".*..."));
        vj.push_back(string(".*..."));
        vj.push_back(string("*...."));
        vj.push_back(string("....."));
        int n1 = convertBoardToNumber(vi);
        int n2 = convertBoardToNumber(vj);

        printf("n1=%d n2=%d\n", normalize(n1), normalize(n2));
        return 0;
    }
};

