#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef unsigned long long UL;
UL gcdShift(UL x, UL y) {
    if ( y > x) return gcdShift(y, x);
    if ( x == 0 ) return y;
    if ( y == 0 ) return x;
    if ( !(x & 1) && !(y & 1)) return gcdShift( x >> 1, y >> 1) << 1;
    if ( (x & 1) && !(y & 1)) return gcdShift( x, y >> 1);
    if ( !(x & 1) && (y & 1)) return gcdShift( x >> 1, y);
    return gcdShift(x-y, y);
}

UL gcdEuclid(UL a, UL b) {
    if (b == 0) return a;
    return gcdEuclid(b, a%b);
}

int main(int argc, char **argv) {
    UL x = atol(argv[1]);
    UL y = atol(argv[2]);
    UL res = gcdShift(x, y);
    cout << "Res = " << res << "\n";
    cout << "Gcd Euclid = " << gcdEuclid(x, y) << "\n";
    return 0;
 }
