#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <bitset>

using namespace std;
const int MAX_SIZE = 1010;

struct Operations {
    Operations(int opType, int x, int y) : _opType(opType), _x(x), _y(y), _k(-1) {}
    Operations(int opType, int k) : _opType(opType), _x(-1), _y(-1), _k(k) {}
    int _opType, _x, _y, _k;
};

const int TOT_INTS = (MAX_SIZE * MAX_SIZE);

struct BitMapArray {

    BitMapArray() {
    }

    int getIndex(int x, int y) { return (x * MAX_SIZE) + y;}

    void setBit(int x, int y, bool value = true) {
        store.set(getIndex(x, y), value);
    }

    void unsetBit(int x, int y) {
        setBit(x, y, false);
    }

    bool isSet(int x, int y) {
        return store.test(getIndex(x, y));
    }

    bitset<TOT_INTS> store;
};


struct State {
    State(int n, int m) : _n(n), _m(m), _totSum(0) {
        init();
    }

    void init() {
        for (int i = 0; i < _n; i++) {
            _flipped[i] = false;
            _rowSum[i] = 0;
        }
    }

    State(): _n(0), _m(0), _totSum(0) {
        init();
    }

    void doOperation1(int x, int y) {
        if (!_flipped[x] && _matrix.isSet(x, y)) return;
        if (_flipped[x] && !_matrix.isSet(x,y)) return;

        _matrix.setBit(x, y, !_flipped[x]);
        _rowSum[x]++;
        _totSum++;
    }

    void doOperation2(int x, int y) {
        if (!_flipped[x] && !_matrix.isSet(x, y)) return;
        if (_flipped[x] && _matrix.isSet(x, y)) return;

        _matrix.setBit(x, y, _flipped[x]);
        _rowSum[x]--;
        _totSum--;
    }

    void doOperation3(int x) {
        _flipped[x] = !_flipped[x];
        int t1 = _rowSum[x];
        int t2 = _m - t1;
        _rowSum[x] = t2;
        _totSum += (t2 - t1);
    }

    void doOperation(const Operations& operation) {
        if (operation._opType == 1) doOperation1(operation._x, operation._y);
        else if (operation._opType == 2) doOperation2(operation._x, operation._y);
        else doOperation3(operation._x);
    }

    int _n, _m;
    BitMapArray  _matrix;
    bool _flipped[MAX_SIZE];
    int _rowSum[MAX_SIZE];
    int _totSum;

};


vector<Operations> operationsVector;
map<int, State> stateByVisitOrder;
set<int> branchingMoves;
//State* statesPtr[MAX_SIZE];

int main() {
    int m, n, q;
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        int opType, x, y, k;
        cin >> opType;
        if (opType < 3) {
            cin >> x >> y;
            operationsVector.push_back(Operations(opType, x, y));
        } else if (opType == 3) {
            cin >> x;
            operationsVector.push_back(Operations(opType, x, -1));
        } else {
            cin >> k;
            operationsVector.push_back(Operations(opType, k));
            branchingMoves.insert(k);
        }
        //statesPtr[i] = NULL;
    }

    State state(n, m);
    //State* ptr = new State(state);
    //int statesPtrPos = 0;
    //statesPtr[statesPtrPos++] = ptr;
    //stateByVisitOrder.insert(make_pair(0, ptr));
    stateByVisitOrder.insert(make_pair(0, state));

    size_t pos = 1;
    for (auto it : operationsVector) {
        if (it._opType < 4) {
            state.doOperation(it);
            /*
            if (branchingMoves.count(pos) == 1) {
                State* ptr = new State(state);
                statesPtr[statesPtrPos++] = ptr;
                stateByVisitOrder.insert(make_pair(pos, ptr));
            }
            */
        } else {
            /*
            State* statePtr = stateByVisitOrder[it._k];
            stateByVisitOrder.insert(make_pair(pos, statePtr));
            state = *statePtr;
            */
            state = stateByVisitOrder[it._k];
        }
        if (branchingMoves.count(pos) == 1) {
            stateByVisitOrder.insert(make_pair(pos, state));
        }

        cout << state._totSum << "\n";
        pos++;
    }

    return 0;
}
