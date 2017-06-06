#include <iostream>
#include <array>
#include <queue>
#include <set>


using namespace std;

const int MX_SZ = (((int)1e5)*3) + 10;
using PI = pair<int, int>;
using VI = vector<int>;
const int MIN_STRENGTH = (((int)1e9) * -1) -20;
const bool dbg = !true;

#define FORN(I, N) for(int (I) = 0; (I) < (N); (I)++)
struct A {

    void start() {
        visited.fill(false);
        strengthOfBank.fill(0);
        cin >> n;
        PI sp = make_pair(MIN_STRENGTH, -1);
        FORN (i, n) {
            int t;
            cin >> t;
            strengthOfBank[i+1] = t;
            if (t > sp.first) sp = make_pair(t, i+1);
        }
        FORN (i, n-1) {
            int t1, t2;
            cin >> t1 >> t2;
            adjList[t1].push_back(t2);
            adjList[t2].push_back(t1);
        }

        int res = MIN_STRENGTH;
        pq.push(sp);
        while (!pq.empty()) {
            PI t = pq.top();
            if (dbg) cout << "Cost=" << t.first << " index=" << t.second << "\n";
            pq.pop();
            if (visited[t.second]) continue;

            res = max(res, t.first);
            if (dbg) cout << "res=" << res << "\n";

            set<int> ts = getIndicesWhoseCostIsToBeIncremented(t.second);
            for (auto it : ts) strengthOfBank[it]++;

            for (auto it : adjList[t.second]) pq.push(make_pair(strengthOfBank[it], it));

            visited[t.second] = true;
        }
        cout << res << "\n";
    }
    set<int> getIndicesWhoseCostIsToBeIncremented(int parent) {
        //insert all neighbors.
        set<int> res;
        for (auto it : adjList[parent]) {
            res.insert(it);
            if (visited[it]) continue;
            res.insert(adjList[it].begin(), adjList[it].end());
        }
        return res;
    }

    array<bool, MX_SZ> visited;
    priority_queue<PI> pq; //value, index;
    array<VI, MX_SZ> adjList;
    array<int, MX_SZ> strengthOfBank;
    int n;
};

A a;
int main() {
    ios::sync_with_stdio(false);
    a.start();
    return 0;
}


