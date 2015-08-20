#include <bits/stdc++.h>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using VI = vector <int>;
using MAP = unordered_map<int, VI>; 
const bool dbg = true;
const int MD = 22;
const int CHARS = 26;

typedef long long LL;
const int MX_SZ = (int)5e5 + 10;

struct PI {
    int first, second, _depth;
    int _parentByHeight[MD];
    int _sigma[CHARS];

    PI() {
        first = second = -1;
        _depth = 0;
        memset(_parentByHeight, 0, sizeof(int) * MD);
        memset(_sigma, 0, sizeof(int) * CHARS);
    }

    void copyParentByHeight(const PI& other) {
        for (int i = 0; i < MD; i++) 
            _parentByHeight[i] = other._parentByHeight[i];
    }

    void copySigma(const int *sigma) {
        for (int i = 0; i < CHARS; i++) {
            _sigma[i] = sigma[i];
        }
    }

    void print() {
        cout << "Parent = " << first << " Char = " <<  (char) ('a' + second) << 
            " depth = " << _depth << "\n";
        for (int i = 0; i < MD; i++) {
            if (_parentByHeight[i] != 0) {
                cout << "P at height " << i << " = " << _parentByHeight[i] << "\n";
            }
        }

        for (int i = 0; i < CHARS; i++) {
            if (_sigma[i] != 0) {
                cout << "Char = " << (char)('a' + i) << " has count " << _sigma[i] << "\n";
            }
        }
    }
};

struct C {
    VI _map[MX_SZ];
    PI _pInfo [MX_SZ];
    VI _lot[MD];
    VI _travOrder;
    int _nodeChars[CHARS];

    int _n, _m;

    bool solve(int nodeId, int depth) {
        fillNodeChars(nodeId, depth);
        //if (dbg) printNodeChars();
        return isPossible();
    }

    void resetNodeChars() {
        memset(_nodeChars, 0, sizeof(int) * CHARS);
    }

    /*
    void printNodeChars() {
        for (int i = 0; i < CHARS; i++) {
            cout << "Char = " << (char) (i + 'a') << " COunt : " << _nodeChars[i] << "\n";
        }
    }
    */

    size_t findLeftStartPos(int parentNodeId, int depth, bool isRight = false) {
        VI& nodesAtLevel = _lot[depth];
        int parentDepth = _pInfo[parentNodeId]._depth;
        unordered_map <int, int>pLevelNodes;
        int pos = 0;
        for (auto &i : _lot[parentDepth]) {
            pLevelNodes.emplace(i, pos++);
        }
        int l = 0; int r = nodesAtLevel.size();
        size_t res = -1;
        while (l < r) {
            int m = (l + r) >> 1;
            // if (dbg) printf("[l=%d, r=%d, m=%d] ", l, r, m);
            int parentId = _pInfo[nodesAtLevel[m]]._parentByHeight[parentDepth];

            if (parentId == parentNodeId) {
                if (!isRight) {
                    r = res = m;
                } else {
                    l = res = m;
                    l++;
                }
            } else if (pLevelNodes[parentId] < pLevelNodes[parentNodeId]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return res;
    }

    size_t findRightStartPos(int parentNodeId, int depth) {
        return findLeftStartPos(parentNodeId, depth, true);
    }

    void fillNodeChars(int nodeId, int depth) {
        int heightParent = _pInfo[nodeId]._depth;
        if (heightParent >= depth) return;
        size_t pos = findLeftStartPos(nodeId, depth);
        size_t posR = findRightStartPos(nodeId, depth);
        VI& nodesAtLevel = _lot[depth];

        PI& leftNode = _pInfo[nodesAtLevel[pos]];
        PI& rightNode = _pInfo[nodesAtLevel[posR]];
        for (int i = 0; i < CHARS; i++) {
            _nodeChars[i] = rightNode._sigma[i] - leftNode._sigma[i];
            /*
            if (dbg) {
                cout << "Left = \n";
                leftNode.print();
                cout << "Right = \n";
                rightNode.print();
            }
            */
        }
        _nodeChars[leftNode.second]++;
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

    void doDfs(int nodeId = 1, int depth = 1, int parentNodeId = 0) {
        if (parentNodeId != 0)  {
            _pInfo[nodeId].copyParentByHeight(_pInfo[parentNodeId]);
            _pInfo[nodeId]._parentByHeight[depth - 1] = parentNodeId;
        }
        _pInfo[nodeId]._depth = depth;
        _lot[depth].push_back(nodeId);
        //_travOrder.push_back(nodeId);
        depth++;
        for (auto& childNode: _map[nodeId]) {
            doDfs(childNode, depth, nodeId);
        }
        //_travOrder.push_back(nodeId);
    }

    void memoize() {
        int memz[CHARS] ;
        for (int i = 0; i < MD; i++) {
            memset(memz, 0, sizeof(int) * CHARS);
            for (size_t j = 0; j < _lot[i].size(); j++) {
                int &nodeId = _lot[i][j];
                memz[_pInfo[nodeId].second]++;
                _pInfo[nodeId].copySigma(memz);
            }
        }
    }

    /*
    void printLot() {
        for (int i = 0; i < MD; i++) {
            cout << " Level = " << i << "\n";
            for (auto &j: _lot[i]) cout << j << " ";
            cout << "\n";
        }
    }

    void printPInfo() {
        for (int i = 1; i <= 20; i++) {
            cout << " NodeId = " << i << "\n";
            _pInfo[i].print();
        }
    }
    */
    void start() {
        cin >> _n >> _m;
        REP (i, _n-1) {
            int t;
            cin >> t;
            _pInfo[i+2].first = t;
            _map[t].push_back(i+2);
        }
        REP (i, _n) {
            char t;
            cin >> t;
            _pInfo[i+1].second = ((int)t - 'a');
        }
        doDfs();
        memoize();
      //  if (dbg) printLot();
      //  if (dbg) printPInfo();
        REP (i, _m) {
            resetNodeChars();
            int node, depth;
            cin >> node >> depth;
            cout << (solve(node, depth) ? "Yes": "No") << endl;
        }
    }    
};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
