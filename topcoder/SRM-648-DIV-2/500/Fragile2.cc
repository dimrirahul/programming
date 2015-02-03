
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
#include <cstring>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}
const int SZ = 21;
class Fragile2
{
public:
    vector<string> origMatrix;
    int N;
    int doBfs(vector<string>& matrix) {
        bool visited[SZ];
        memset(visited, 0, sizeof(bool) * SZ);
        int comp = 1;
        REP (i, N) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int f = q.front();
                    q.pop();
                    if (visited[f]) continue;
                    visited[f] = true;
                    REP (j, N) {
                        if (matrix[f][j] == 'Y' && !visited[j]) {
                            q.push(j);
                        }
                    } 
                }
                comp++;
            }
        }
        return comp;
    }
    int countPairs(vector <string> g)
    {
        origMatrix = g;
        N = origMatrix.size();
        int compCount = doBfs(origMatrix);
        int res = 0;
        REP (i, N) {
            for (int j = i + 1; j < N; j++) {
                vector<string> mat = origMatrix;
                REP(k, N) {
                    mat[i][k] = mat[k][i] = mat[j][k] = mat[k][j] = 'N';
                }
                if (doBfs(mat) - compCount > 2) res++;
            }
        }
        return res; 
    }
};

