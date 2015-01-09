
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

const int SIZE = 102;
class PathGameDiv2
{
public:
    bool onOptimal[SIZE];
    bool visited[SIZE];
    int parent[SIZE];

    int getIndex(int r, int c, int s) {
        return r*s + c;
    }

    pair<int, int> getRC(int index, int size) {
        pair<int, int> t = make_pair(-1, -1);
        int r, c;
        r = (index < size) ? 0:1;
        c = index - r * size;
        t.first = r;
        t.second = c;
        return t;
    }
    void insertNeighbors(int index, queue<int> &q,vector<string>& v) {
        printf("Neighbor insert for index=%d\n", index);
        pair<int, int> t = getRC(index, v[0].size());
        int r, c;
        r = t.first;
        c = t.second;
        int s = v[0].size();

        if (c > 0 && !visited[index -1] && v[r][c - 1] == '.') {
            printf("Inserting neighbor=%d\n", index -1);
            q.push(index -1);
            parent[index-1] = index;
        }

        if (c+1 < s && !visited[index + 1] && v[r][c+1] == '.') {
            printf("Inserting neighbor=%d\n", index +1);
            q.push(index +1);
            parent[index+1] = index;
        }

        if ((r < 1) && !visited[index + s] && v[r+1][c] == '.') {
            printf("Inserting neighbor=%d\n", index +s);
            q.push(index +s);
            parent[index+ s] = index;
        }

        if ( r==1 && !visited[index - s] && v[0][c] == '.' ) {
            printf("Inserting neighbor=%d\n", index -s);
            q.push(index -s);
            parent[index -s] = index;
        }
    }
	int calc(vector <string> board)
	{
        REP(i, SIZE) {
            onOptimal[i] = false;
            visited[i] = false;
            parent[i] = -1;
        }

        queue<int> q;
        if (board[0][0] == '.') {
            q.push(0);
        } else {
            q.push(board[0].size());
        }

        while(!q.empty()) {
            int index = q.front();
            q.pop();
            if (!visited[index]) {
                printf("Visiting index =%d\n", index);
                visited[index] = true;
                if ( (index == board[0].size() - 1) || (index == (board[0].size() * 2) -1)) {
                    break;
                }
                insertNeighbors(index, q, board);
            } else {
                printf("Index =%d already visited\n", index);
            }
        }

        int endPos = board[0][board[0].size() -1] == '.' ? board[0].size() -1 : board[0].size() * 2 -1;
        int pi = parent[endPos];
        while (pi != -1) {
            printf("Index=%d has parent=%d\n", endPos, pi);
            onOptimal[endPos] = 1;
            endPos = pi;
            pi = parent[endPos];
        }
        onOptimal[endPos] = 1;
        int count = 0;
        REP(i, 2 * board[0].size()) {
            pair <int, int> t = getRC(i, board[0].size());
            printf("Index = %d is onOptimal=%d, has value=%c\n", i, onOptimal[i], board[t.first][t.second]);
            if (!onOptimal[i] && board[t.first][t.second] == '.') {
                count++;
            }
        }
		return count;
	}
};
