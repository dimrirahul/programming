#include <iostream>
#include <vector>

using namespace std;
using VI = vector<int>;


const int MV = (int) 5e5 + 10;
const int MD = 21;
const int CHARS = 26;

struct NInfo {
    int p, d, fo, so;
    char c;
    VI children;
    NInfo() { p = d = fo = so = -1;}
};

struct CCount {
    int cnt[CHARS];
    CCount() {
        memset(cnt, 0, sizeof(int) * CHARS);
    }
    void append(int x) { cnt[x]++; }
    void append(const CCount& o) { for(int i = 0; i < CHARS; i++) cnt[i] += o.cnt[i];}
};

using VCC = vector<CCount>;
#define pb push_back
#define mp make_pair

struct D {
    VI lot[MD];
    VCC vcc[MD];

    NInfo ninfo[MV];
    int N, Q;
    
    int doDfs(int nId = 1, int depth = 1, int po = 0) {
        NInfo &node = ninfo[nId];
        node.d = depth;
        node.po = po;
        lot[depth].pb(nId);
        for(auto i: node.children) {
            po = doDfs(i, depth+1, ++po);
        }
        node.so = ++po;
        return po;
    }

    void memoize() {
        for (int i = 0; i < MD; i++) {
            VCC &vc = vcc[i];
            for (int j = 0; j < lot[i].size(); j++) {
                CCount c;
                c.append(ninfo[lot[i][j]].c - 'a');
                if (j > 0) c.append(vc[j-1]);
                vc.pb(c);
            }
        }
    }

    int getParentRelPos(int child, int v) {
        if (ninfo[child].so < ninfo[v].fo) return -1;
        if (ninfo[child].fo > ninfo[v].so) return 1;
        return 0;
    }

    int findLeft(int v, int h, bool isRight = false) {
        int l = 0, r = lot[h].size(), res = -1;
        while (l < r) {
            int m = (l + r) >> 1;
            int compVal = getParentRelPos(lot[h][m], v);
            if (compVal == 0) {
                res = m;
                if (!isRight) r = m;
                else l = m+1;
            } else if (compVal < 0) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return res;
    }

    int findRight(int v, int h) {
        return solveLeft(v, h, true);
    }


    bool solve(int v, int h) {
        if ( h <= ninfo[v].d ) return true;
        int lpos = findLeft(v, h);
        int rpos = findRight(v, h);

    }

    void start() {
        cin >> N >> Q;
        for (int i = 0; i < N; i++) cin >> ninfo[i+1].c;
        for (int i = 0; i < N-1; i++) { 
            int t;
            cin >>t;
            ninfo[i+2].p = t;
            nifo[t].children.pb(i+2);
        }
        doDfs();
        memoize();
        for (int i = 0; i < Q; i++) {
            int v, h;
            cin >> v >> h;
            cout << solve(v, h) << "\n";
        }
    }
}


