#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>

using namespace std;

const int MX_ELEMENTS = ((int)1e5) + 20;
const bool dbg = true;

using VI = vector<int>;

#define FORN(I, N) for (int (I) = 0; (I) < (N); (I)++)

int fn(int x) {
    if (x % 2 == 0) return x/2;
    return x/2 + 1;
}

int main() {
    int n;
    VI v;
    cin >> n;
    FORN (i, n) { int t; cin >> t; v.push_back(t);}
    int ev = 0;
    int li = v.size()-1;
    for (VI::reverse_iterator it = v.rbegin(); it != v.rend(); it++, li--) {
        if (dbg) cout << "Ev for index=" << li << " before=" << ev;
        ev = abs(ev - fn(*it));
        if (dbg) cout << " after=" << ev << "\n";
    }
    cout << ev << "\n";

}
