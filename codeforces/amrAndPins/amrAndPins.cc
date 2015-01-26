#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
typedef pair<int, int> PI;
typedef long long UL;
class CLASS {
    public:
        bool isPerfectSq(UL r) {
            UL p = (UL)sqrt(r);
            return r == p * p;
        }
        void start() {
            UL r, x, y, x1, y1;
            cin >> r >> x  >> y >> x1 >> y1;
            //cout << r << " " << x << " " << y << " " << x1 << " " << y1 << "\n"; 
            //scanf("%d %d %d %d %d\n", &r, &x, &y, &x1, &y1);
            UL dInt = (x - x1) * (x - x1) +  (y - y1) * (y - y1);
            //cout << "DIst = " << dInt << "\n";
            bool divides = false;
            if ( dInt % ( 4 *  r * r ) == 0 && isPerfectSq(dInt / (4 * r* r)) ) {
                divides = true;
            }
            //cout << "Divides =" << divides << "\n";
            UL p = dInt / ( 4 * r * r );
            int res = (int) sqrt(p);
            if (divides) {
                cout << res << "\n";
            } else {
                cout << res + 1 << "\n";
            }
        }
};

CLASS kt;
int main(int argc, char **argv) {
    kt.start();
    return 0;
}
