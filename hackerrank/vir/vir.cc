#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;
const bool dbg = !true;

const int P = ((int)1e9) + 7;

LL getMod(LL x) {
    LL res = x % P;
    if (res >=0 ) return res;
    return res + P;
}

LL mult(LL a, LL b) {
    return getMod(getMod(a) * getMod(b));
}

LL mult(LL a, LL b, LL c) {
    return mult(mult(a, b), c);
}

LL getPow(LL base, LL pow) {
    if (dbg) cout << "getPow solving for base= " << base << " pow=" << pow << "\n";
    if (pow == 0) return (LL)1;
    if (pow == 1) return getMod(base);
    LL np = pow/2;
    LL hr = getPow(base, np);
    LL remp = pow % 2;
    return mult(hr, hr, getPow(base, remp));
}

int main() {
    LL t;
    int a, b;
    cin >> a >> b >> t;
    LL base = (a + b)/2;
    LL den = base - 1;
    if (dbg) cout << "t=" << t << " a=" << a << " b=" << b << " base=" << base << " den=" << den << "\n";
    LL res = getPow(base, t);
    //res = (res - 1)/den;
    cout << res << "\n";
    return 0;
}
