#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
using PI = pair<int, int>;
const int MX_SZ = 200000 + 10;
struct Triple {
    Triple() { _a = _b = _c = 0; }
    int _a, _b, _c;
};

using VT = vector<Triple>;
unordered_map<int, int> _countByLang;
struct C {

    int _n, _m;
    VT _triple;

    struct Comp {
        bool operator()(const Triple& a, const Triple& b) const {
            if (_countByLang[a._b] != _countByLang[b._b]) return _countByLang[a._b] < _countByLang[b._b];
            return _countByLang[a._c] < _countByLang[a._c];
        }
    };

    void start() {
        Comp comp;
        cin >> _n;
        for (int i = 0; i < _n; i++) {
            int t; cin >> t;
            auto it = _countByLang.find(t);
            if (it == _countByLang.end()) _countByLang.insert(make_pair(t, 1));
            else it->second++;
        }

        cin >> _m;
        for (int i = 0; i < _m; i++) {
            Triple t;
            t._a = i + 1;
            cin >> t._b;;
            _triple.push_back(t);
        }

        for (int i = 0; i < _m; i++) {
            cin >> _triple[i]._c;
        }

        sort(_triple.begin(), _triple.end(), comp);
        cout << _triple.back()._a << "\n";
    }
};

C c;
int main(int argc, char **Argv) {
    c.start();
    return 0;
}
