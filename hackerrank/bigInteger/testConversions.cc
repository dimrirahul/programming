#include <iostream>

using namespace std;
using LL = long long;
int main() {
    LL t = 1L;
    t = (t << 63) -1;
    cout << "T=" << t << "\n";
    int l = (int)t;
    LL t1 = (t >> 32);
    LL t2 = (t1 << 32);
    cout << "L=" << l << "\n";
    cout << "T1 (higher32 bits)=" << t1 << " T2(Lower32 Bits)=" << t2 << "\n";
    cout << "int casted higherBits=" << (int)t1 << " int casted lowerbits=" << (int)t2 << "\n";
    return 0;
}
