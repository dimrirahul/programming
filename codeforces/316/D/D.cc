#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
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
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#include <cassert>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;
using VI = vector <int>;
using VS = vector <string>;
using MAP = unordered_map<int, VI>; 
using SMap = unordered_map<int, int>;
const bool dbg = true;

typedef long long LL;
const int MX_SZ = (int)5e5 + 10;
struct C {
    MAP _map;
    PI _pInfo [MX_SZ];
    int _n, _m;

    bool solve(int nodeId, int depth) {
        SMap table;
        solve(nodeId, depth, table);
        return isPossible(table);
    }
    void solve(int nodeId, int depth, SMap& table) {
        if (depth == 0) return;
        if (dbg) {
            cout << " Visiting nodeId: " << nodeId << " Depth: " << depth << "\n";
        }
        auto it = table.find(_pInfo[nodeId].second);
        if ( it != table.end()) it->second++;
        else table.emplace(_pInfo[nodeId].second, 1);
        depth--;
        if (dbg) {
            auto it1 = table.find(_pInfo[nodeId].second);
            cout << " Char = " << (char) it1->first << " has count of " << it1->second << " new Depth = " << depth << "\n";
        }
        if (_map.find(nodeId) == _map.end()) return;
        for (auto& it: _map[nodeId]) solve(it, depth, table);
    }

    bool isPossible(SMap& table) {
        int odd = 0, even = 0, tot = 0;
        for (auto& it: table) {
            if ( (it.second & 1) == 1) odd++;
            else even++;
            tot += it.second;
        }
        if ( (tot & 1) == 0 ) return odd == 0;
        else return odd == 1;
    }
    void start() {
        REP (i, MX_SZ) _pInfo[i].first = _pInfo[i].second = -1;
        cin >> _n >> _m;
        REP (i, _n-1) {
            int t;
            cin >> t;
            _pInfo[i+2].first = t;
            auto it = _map.find(t);
            if (it == _map.end()) {
                VI v;
                v.push_back(i+2);
                _map.emplace(t, v);
            } else {
                it->second.push_back(i+2);
            }
        }
        REP (i, _n) {
            char t;
            cin >> t;
            _pInfo[i+1].second = t;
        }
        REP (i, _m) {
            int node, depth;
            cin >> node >> depth;
            cout << (solve(node, depth) ? "Yes": "No") << "\n";
        }
    }    
};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
