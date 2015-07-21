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


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;
using VI = vector <int>;
using VS = vector <string>;
typedef long long LL;
using PL = pair <LL, LL>;
using VL = vector<LL>;
const bool dbg = !true;
struct Gap {
    int idx;
    LL d, maxLen;
    PL l, r;
    Gap(int _idx, PL _l, PL _r): idx(_idx), l(_l), r(_r) {
        d = r.first - l.second;
        maxLen = r.second - l.first;
    }
    bool operator<(Gap o) const {
        return maxLen < o.maxLen;
    }
    bool canFit(const LL b) {
        return !( b < d || b > maxLen);
    }
    string toString() {
        stringstream ss;
        ss << "Idx:" << idx << " d:" << d << " Left:[" << l.first << "," << l.second << "] right:[" << r.first << "," << r.second << "]";
        return ss.str();
    }
};
using VG = vector<Gap>;
struct D {
    map<LL, VI> distanceToName;
    VG vg;
    void start() {
        int n, k;
        cin >> n >> k;
        PL prev;
        REP(i, n) {
            LL f, s;
            cin >> f >> s;
            PL curr = make_pair(f, s);
            if (i != 0) {
                vg.push_back(Gap(i, prev, curr));
            }
            prev = curr;
        }
        REP(i, k) {
            LL t; cin >> t;
            map<LL, VI>::iterator it = distanceToName.find(t);
            if (it != distanceToName.end()) {
                it->second.push_back(i+1);
            } else {
                distanceToName.insert(make_pair(t, VI({i+1})));
            }
        }
        sort(ALL(vg));
        if (dbg) {
            for (auto& i: vg) cout << i.toString() << "\n";
            for (auto& i: distanceToName) {
                cout << "Key=" << i.first << " [" ;
                for (auto &j: i.second) cout << j << " ";
                cout << "]\n";
            }
        }
        VI res(vg.size());
        bool possible = true;
        for (auto& gap: vg) {
            auto it = distanceToName.lower_bound(gap.d);
            if (it == distanceToName.end()) {
                if (dbg) cout << gap.d << " was not found as key\n ";
                possible = false;
                break;
            }
            if (gap.canFit(it->first)) {
                int id = (it->second)[it->second.size() -1];
                it->second.pop_back();
                if (it->second.size() == 0) distanceToName.erase(it);
                res[gap.idx - 1] = id;
            } else {
                if (dbg) cout << gap.toString() << " could not fit " << it->first << "\n";
                possible = false;
                break;
            }
        }
        if (!possible) cout << "No\n";
        else {
            cout << "Yes\n";
            for (auto &i: res) cout << i << " ";
            cout << "\n";
        }
    }    
};

D t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
