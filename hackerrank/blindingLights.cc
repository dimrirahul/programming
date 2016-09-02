#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>

using namespace std;

const int MX_SZ = 410;
int edges[MX_SZ][MX_SZ];
int result[MX_SZ][MX_SZ];
const int INF = 360 * 410;
using PI = pair<int, int>;

struct Cmp {
    bool operator()(const PI& f, const PI& s) const {
        return f.first > s.first;
    }
};

using PQ = priority_queue<PI, vector<PI>, Cmp>;
#define REP(I, N) for (int (I) = 0; (I) < (N); (I)++)
void findAllPairShortestPath(int src, int numNodes) {
    PQ pq;
    pq.push(make_pair(0, src));
    set<int> visited;
    while (!pq.empty()) {
        PI p = pq.top();
        pq.pop();
        if (visited.count(p.second)) continue;
        visited.insert(p.second);
        result[src][p.second] = p.first;
        for (int i = 1; i <= numNodes; i++) {
            if (edges[p.second][i] != INF && visited.count(i) == 0) {
                pq.push(make_pair(p.first + edges[p.second][i], i));
            }
        }
    }
}

int main() {
    int n, m, q;
    REP(i, MX_SZ)
        REP(j, MX_SZ)
            edges[i][j] = result[i][j] = INF;
    cin >> n >> m;
    REP(i, m) {
        int s, d, c;
        cin >> s >> d >> c;
        edges[s][d] = c;
    }
    for (int i = 1; i <= n; i++) findAllPairShortestPath(i, n);
    cin >> q;
    REP(i, q) {
        int s, d;
        cin >> s >> d;
        int res = result[s][d] != INF ? result[s][d] : -1;
        cout <<  res << "\n";
    }
    return 0;
}
