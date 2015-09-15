#include <bits/stdc++.h>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
using namespace std;

#define MP make_pair
#define PB push_back
using VI = vector <int>;
using MAP = unordered_map<int, VI>;
const int MAX_DEPTH = 22;
const int CHARS = 26;
const bool dbg = !true;

const int MX_SZ = (int)5e5 + 10;

struct PI {
    int _f, _s, _t, _beg, _end; //parent, char, depth, begPos, endPos
    PI(int f, int s, int t): _f(f), _s(s), _t(t) { _beg = _end = -1;}
    PI(): _f(0), _s(0), _t(0) {}
};

struct C {
    int _n, _m;
    VI _lot[MAX_DEPTH];
    MAP _cById;
    PI _pi[MX_SZ];
    int _nodeChars[CHARS];
    map<pair<int, int>, bool> _qCache;

    void resetNodeChars() { memset(_nodeChars, 0, sizeof(int) * CHARS);}


    void start() {
        cin >> _n >> _m;
        _pi[0] = PI(0, -1, 0);
        _pi[1] = PI(0, 0, 1);
        REP (i, _n-1) {
            int t;
            cin >> t;
            _pi[i+2]._f = t;
            _cById[t].push_back(i+2);
        }
        REP (i, _n) {
            char t;
            cin >> t;
            _pi[i+1]._s = ((int)t - 'a');
        }
        doDfs();
        for (int i = 0; i < _m; i++) {
            resetNodeChars();
            int node, depth;
            cin >> node >> depth;
            cout << (solve(node, depth) ? "Yes": "No") << endl;
        }
    }    

    int doDfs(int nodeId = 1, int depth = 1, int pos = 0) {
        _pi[nodeId]._t = depth;
        _pi[nodeId]._beg = pos;
        _lot[depth].push_back(nodeId);
        for (auto &i: _cById[nodeId]) {
            pos = doDfs(i, depth+1, pos+1); 
        }
        pos++;
        _pi[nodeId]._end = pos;
        return pos;
    }

    bool hasAncestor(int childId, int parentId) {
        if (dbg) cout << " Has Ancestor called with " << childId << " " << parentId << "\n";
        if (childId <= parentId) return false;
        bool res =  _pi[childId]._beg > _pi[parentId]._beg &&
            _pi[childId]._end < _pi[parentId]._end;
        if (dbg) cout << "Has Ancestor = " << res << " for " << childId << " " << parentId << "\n";
        return res;
    }

    bool hasAncestorToLeft(int childId, int parentId) {
        bool res = _pi[childId]._end < _pi[parentId]._beg;
        if (dbg) cout << "Has Ancestor to left = " << res << " for " << childId << " " << parentId << "\n";
        return res;
    }

    int findNode(int v, int d, bool isLeft = true) {
        VI& nodes = _lot[d];
        int l = 0, r = nodes.size(), res = -1;
        while (l < r) {
            int m = (l+r) / 2;
            if (hasAncestor(nodes[m], v)) {
                if (isLeft) {
                    res = r = m;
                } else {
                    res = m;
                    l = m + 1;
                }
            } else if (hasAncestorToLeft(nodes[m], v)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return res;
    }

    bool solve(int node, int depth) {
        pair<int, int> query = MP(node, depth);
        auto iter = _qCache.find(query);
        if (iter != _qCache.end()) return iter->second;
        int d = depth - _pi[node]._t;
        if ( d <= 0) return true;
        int l = findNode(node, depth);
        int r = findNode(node, depth, false);
        if (l == r) return true;
        for (int i =l; i <= r; i++) {
            _nodeChars[_pi[_lot[depth][i]]._s]++;
        }

        bool res = isPossible();
        _qCache.emplace(query, res);
        return res;
    }

    bool isPossible() {
        int odd = 0, even = 0, tot = 0;
        for (int it = 0; it < CHARS; it++) {
            if ( (_nodeChars[it] & 1) == 1) odd++;
            else even++;
            tot += _nodeChars[it];
        }
        if ( (tot & 1) == 0 ) return odd == 0;
        else return odd == 1;
    }

};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
