#include <bits/stdc++.h>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
using namespace std;

#define MP make_pair
#define PB push_back
using VI = vector <int>;
using MAP = unordered_map<int, VI>;
const bool dbg = !true;
const int MAX_DEPTH = 22;
const int CHARS = 26;

const int MX_SZ = (int)5e5 + 10;

struct PI {
    int _f, _s, _t; //parent, char, depth
    PI(int f, int s, int t): _f(f), _s(s), _t(t) {}
    PI(): _f(0), _s(0), _t(0) {}
    void print() {
        printf("PI [parent=%d, char=%c, depth=%d]\n", _f, _s + 'a', _t);
    }
};
struct MD {
    int _cnt[CHARS];
    MD() { memset(_cnt, 0, sizeof(int) * CHARS); }
    void print() {
        cout << "Chars = [";
        for (int i = 0; i < CHARS; i++) cout << _cnt[i] << ",";
        cout << "]\n";
    }

};
struct LI {
    unordered_map<int, int> _posById;
    vector<MD> _mdv;
    void print() {
        cout << "MAP = [ID, POS] " << "\n";
        for (auto i : _posById) {
            cout << "[" << i.first << "," << i.second << "] ";
        }
        for (auto& i: _mdv) {
            i.print();
        }
    }
};

struct C {
    int _n, _m;
    VI _lot[MAX_DEPTH];
    MAP _cById;
    LI _li[MAX_DEPTH];
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
        doBfs();
        memoize();
        if (dbg) {
            for (int i = 1; i <= _n; i++)  _pi[i].print();
        }
        for (int i = 0; i < _m; i++) {
            resetNodeChars();
            int node, depth;
            cin >> node >> depth;
            cout << (solve(node, depth) ? "Yes": "No") << endl;
        }
    }    

    void doBfs() {
        using PAIR = pair <int, PI>;
        queue<PAIR> q;
        q.push(MP(1, _pi[1]));
        while (!q.empty()) {
            PAIR p = q.front();
            q.pop();
            _lot[p.second._t].PB(p.first);
            for (auto &i: _cById[p.first]) {
                _pi[i]._t = p.second._t + 1;
                q.push(MP(i, _pi[i]));
            }
        }
    }

    void memoize() {
        int d = -1;
        for (auto &vi: _lot) {
            d++;
            int pos = 0;
            for (auto &i: vi) {
                _li[d]._posById.emplace(i, pos++);
                MD md;
                vector <MD> &mdv = _li[d]._mdv;
                if (mdv.size() != 0) md = mdv[mdv.size() - 1];
                md._cnt[_pi[i]._s]++;
                mdv.push_back(md);
            }
        }
    }

    int getParent(int nodeId, int d) {
        while (d > 0) {
            nodeId = _pi[nodeId]._f;
            d--;
        }
        return nodeId;
    }

    int findNode(int v, int d, bool isLeft = true) {
        VI& nodes = _lot[d];
        int pDepth = _pi[v]._t;
        unordered_map<int, int> &mp = _li[pDepth]._posById;
        int l = 0, r = nodes.size(), res = -1;
        while (l < r) {
            int m = (l+r) / 2;
            int pId = getParent(nodes[m], d - pDepth);
            if (pId == v) {
                if (isLeft) {
                    res = r = m;
                } else {
                    res = m;
                    l = m + 1;
                }
            } else if (mp[pId] < mp[v]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (dbg) cout << "Res ============ " << res << "\n";
        return nodes[res];
    }

    bool solve(int node, int depth) {
        if (dbg) {
            cout << "SOlve ------ nodeId = " << node << "\n";
            _pi[node].print();
            cout << "---------";
        }
        pair<int, int> query = MP(node, depth);
        auto iter = _qCache.find(query);
        if (iter != _qCache.end()) return iter->second;
        int d = depth - _pi[node]._t;
        if ( d <= 0) return true;
        int l = findNode(node, depth);
        int r = findNode(node, depth, false);
        if (l == r) return true;
        LI &lid = _li[depth];
        MD& leftData = lid._mdv[lid._posById[l]];
        MD& rightData = lid._mdv[lid._posById[r]];
        
        if (dbg) {
            cout << "LeftNodeId = " << l << " rightnodeId = " << r << 
                " Left Pos = " << lid._posById[l] <<
                " Right Pos = " << lid._posById[r] << "\n";
            cout << " Left MD = \n";
            leftData.print();

            cout << "Right MD = \n";
            rightData.print();
        }

        for (int i = 0; i < CHARS; i++) {
            _nodeChars[i] = rightData._cnt[i] - leftData._cnt[i];
        }

        if (dbg) {
            cout << " Mystery = ";
            _pi[l].print();
        }

        _nodeChars[_pi[l]._s]++;
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
