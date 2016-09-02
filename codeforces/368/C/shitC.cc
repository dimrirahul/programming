#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

using VI = vector<int>;
using LL = long long;

const bool dbg = !true;

VI U = {1, 2, 2, -2, -1, -2, 2, 2, 3};
VI A = {1, 2, 2, 2, 1, 2, 2, 2, 3};
VI D = {-1, -2, -2, 2, 1, 2, 2, 2, 3};

const LL MAX_NUM = 1e9 + 200;
struct Triple;
struct Triple {
    Triple(LL a, LL b, LL c) : _a(a), _b(b), _c(c) {}
    Triple() : _a(0), _b(0), _c(0) {}

    LL _a, _b, _c;

    Triple mult(const VI& v) const {
        LL a = _a * v[0] + _b * v[3] + _c * v[6];
        LL b = _a * v[1] + _b * v[4] + _c * v[7];
        LL c = _a * v[2] + _b * v[5] + _c * v[8];
        return Triple(a, b, c);
    }

    Triple multU() const {return mult(U);}
    Triple multA() const {return mult(A);}
    Triple multD() const {return mult(D);}

    bool hasN(LL n, Triple& res) {
        if (scale(n, _a, res)) return true;
        if (scale(n, _b, res)) return true;
        if (scale(n, _c, res)) return true;
        return false;
    }

    bool validateTriangle() {
        return (_a + _b >= _c) && (_a + _c >= _b) && (_b + _c >= _a);
    }

    bool allGt(LL n) {
        return n < _a && n < _b && n < _c;
    }

    bool searchRecursively(LL n, Triple& res, int depth = 0) {
        if (dbg) cout << "Looking at: " << _a << " " << _b << " " << _c << "\n";
        if (!validateTriangle()) return false;
        if (_a >= MAX_NUM || _b >= MAX_NUM || _c >= MAX_NUM) return false;
        if (hasN(n, res)) return true;
        return multU().searchRecursively(n, res, depth + 1) ||
            (!allGt(n) && multA().searchRecursively(n, res, depth + 1)) ||
            multD().searchRecursively(n, res, depth + 1);
    }

    bool scale(LL n, LL v, Triple& res) {
        if (n % v == 0) {
            LL scale = n / v;
            res._a = _a * scale;
            res._b = _b * scale;
            res._c = _c * scale;
            return true;
        }
        return false;
    }

};

int main() {
    LL n;
    cin >> n;
    Triple triple(3, 4, 5);
    Triple res;
    LL one = 1;

    if (n != one && triple.searchRecursively(n, res)) {
        if (dbg) cout << "Triple as ans= " << res._a << " " << res._b << " " << res._c << "\n";
        vector<LL> v;
        if (n == res._a) { v.push_back(res._b); v.push_back(res._c);}
        if (n == res._b) { v.push_back(res._c); v.push_back(res._a);}
        if (n == res._c) { v.push_back(res._a); v.push_back(res._b);}
        cout << v[0] << " " << v[1] << "\n";
    } else {
        cout << "-1" << "\n";
    }
    return 0;

}
