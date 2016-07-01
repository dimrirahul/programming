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
#include <unordered_set>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;
using VI = vector <int>;
using VS = vector <string>;
using VPI = vector<PI>;

const bool dbg = !true;
typedef long long LL;
const int MX_SZ = 4008;
namespace std {
    template <> struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };
}
struct A {
    bool mat[MX_SZ][MX_SZ];
    int reco[MX_SZ];
    int _n, _m;

    bool matched(VPI& sv, int pos1, int pos2) {
        int p1 = sv[pos1].second;
        int p2 = sv[pos2].second;
        return mat[p1][p2] || mat[p2][p1];
    }

    int doSortedSearch(VPI& sv) {
        sort(ALL(sv));
        //int res = 5000 * 3;;
        int res = -1;
        bool done = false;
        for (int i = 0; i < sv.size() && !done ; i++) {
            for (int j = i + 1; j < sv.size() && !done ; j++) {
                if (!matched(sv, i, j)) continue;
                for (int k = j + 1; k < sv.size() && !done; k++) {
                    if (!(matched(sv, j, k) && matched(sv, i, k)) ) {
                        continue;
                    }
                    int t = sv[i].first + sv[j].first + sv[k].first;
                    t -= 6;
                    res = t;
                    done = true;
                }
            }
        }
        //if (res == 5000 * 3) return -1;
        return res;
    }

    void start() {
        memset(reco, 0, sizeof(int) * MX_SZ);
        REP(i, MX_SZ) REP(j, MX_SZ) mat[i][j] = false;

        cin >> _n >> _m;
        REP(i, _m) {
            int t1, t2; cin >> t1 >> t2;
            t1--; t2--;
            //mat.insert(make_pair(t1, t2));
            mat[t1][t2] = true;;
            reco[t1]++; reco[t2]++;
        }
        VPI sv;
        for (int i = 0; i < _n; i++) {
            sv.push_back(make_pair(reco[i], i));
            if (dbg) cout << " Idx i = " << i << " val = " << reco[i] << "\n";
        }
        
        cout << doSortedSearch(sv) << "\n";
    }
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
