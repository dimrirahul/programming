#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

const int MAX_SZ = 3005;
int edgeCost[MAX_SZ][MAX_SZ];
const int MX_VAL = 999999;
using PI = pair<int, int>;
const bool dbg = !true;

void clear() {
    for (int i = 0; i < MAX_SZ; i++)
        for (int j = 0; j < MAX_SZ; j++)
            edgeCost[i][j] = MX_VAL;
}

struct Cmp {
    bool operator()(const PI& p1, const PI& p2) const {
        return p1.first > p2.first;
    }
};

using PQ = priority_queue<PI, vector<PI>, Cmp>;

void pushNeighbors(int src, int srcCost, PQ& pq) {
    for (int j = 0; j < MAX_SZ; j++) {
        if (edgeCost[src][j] != MX_VAL) {
            if (dbg) cout << "inserting node " << j << " with cost " << edgeCost[src][j] + srcCost << "\n";
            pq.push(make_pair(edgeCost[src][j] + srcCost, j));
        }
    }
}

int main() {
    int ntc; cin >> ntc;
    for (int i = 0; i < ntc; i++) {
        clear();
        int n, m, sn;
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            int t1, t2, cost;
            cin >> t1 >> t2 >> cost;
            edgeCost[t1][t2] = min(edgeCost[t1][t2], cost);
            edgeCost[t2][t1] = edgeCost[t1][t2];
        }
        cin >> sn;
        map<int, int> res;
        PQ pq;
        pushNeighbors(sn, 0, pq);
        res.insert(make_pair(sn, 0));
        while (!pq.empty()) {
            PI p = pq.top();
            pq.pop();
            if (dbg) cout << "Popped :" << p.second << " with distance: " << p.first << "\n";
            if (res.find(p.second) != res.end()) {
                if (dbg) cout << " Continuing as " << p.second << " is already visited" << "\n";
                continue;
            }
            pushNeighbors(p.second, p.first, pq);
            res.insert(make_pair(p.second, p.first));
        }
        bool isFirst = true;
        for (int j = 1; j <= n; j++) {
            int o = -1;
            if (j == sn) continue;
            if (res.count(j)) o = res[j];
            if (!isFirst) cout << " ";
            cout << o;
            isFirst = false;
        }
        cout << "\n";
        if (dbg) cout << "Ran tc: " << i << "\n";
    }
    return 0;
}
