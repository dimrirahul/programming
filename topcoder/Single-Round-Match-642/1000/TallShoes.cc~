
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

const int SZ = 50;
typedef pair<int, int> PI;
typedef long long LL;
const LL inf = 1e17;
class Node {
    public:
        int id;
        LL cost;
        Node(int i, LL c) { id = i; cost = c; }
        bool operator<(Node other) const {
            return (cost > other.cost);
        }
};
class TallShoes
{
public:
    LL matrix[SZ][SZ];
    LL pathCost[SZ];

	int maxHeight(int n, vector <int> x, vector <int> y, vector <int> h, long long b) 
	{
        int sz = x.size();
        REP (i, n) {
            REP (j, n) {
                matrix[i][j] = LL(-1);
            }
        }

        int ans = 0;
        int start = 0, end = 1e9;
        priority_queue< Node, vector <Node> > pq;
        while (start < end) {
            LL cost = (LL) 0;
            int mid = (start+end) / 2;
            //printf("Test height=%d\n", mid);
            REP (i, sz) {
                matrix[x[i]][y[i]] = matrix[y[i]][x[i]] = (mid - h[i] > 0) ? ( (LL) (mid - h[i])) * (mid - h[i]) : (LL)0;
            }
            REP (i, n) pathCost[i] = inf;
            /*
            REP (i, n) {
                REP (j, n) {
                    printf("%lld ", matrix[i][j]);
                }
                printf("\n");
            }
            */
            pq.push(Node(0, 0));
            while (!pq.empty()) {
                Node n1 = pq.top();
                pq.pop();
                if (pathCost[n1.id] != inf)  {
                   // printf("%d is already present continiuing\n", n1.id);
                    continue;
                }
                cost += n1.cost;
                pathCost[n1.id] = cost;
                //printf("visiting node=%d, cost = %lld\n", n1.id, cost);
                REP(i, n) {
                    if (matrix[n1.id][i] >= 0 && pathCost[i] == inf) {
                  //      printf("pushing nodeId=%d cost=%lld\n", i, matrix[n1.id][i]);
                        pq.push(Node(i, matrix[n1.id][i]));
                    }
                }
            }
            LL jc = inf;
            REP(i, n-1) {
                if (matrix[i][n-1] >= 0) {
                    jc = min(jc, pathCost[i] + matrix[i][n-1]);
                }
            }
            //printf("cost =%lld have money=%lld\n", jc, b);
            if (jc <= b) {
                start = mid+1;
                ans = max(ans, mid);
            } else {
                end = mid;
            }

        }
        return ans;
	}
};

