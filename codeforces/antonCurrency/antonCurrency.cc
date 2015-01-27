#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 100001;
class Num {
    public:
    int p, h, l;
    Num() {
        p = -1;
        h = -1;
        l = -1;
    }

    Num(int _p, int _h, int _l) {
        p = _p;
        h = _h;
        l = _l;
    }
    bool operator<(Num other) const {
        if (p != other.p) return p < other.p;
        if (h != other.h) return h < other.h;
        return l < other.l;
    }

};
class antonCurrency {
public:
    char buff[SZ];
    void start() {
        scanf("%s\n", buff);
        int len = strlen(buff);
        int pos = -1;
        Num maxV;
        for (int i = 0; i < len; i++) {
            if ((buff[i] - '0') % 2 == 0) {
                pos = i;
                Num t(len -1 - i,buff[len - 1] - '0', buff[i] - '0');
                if (maxV < t) {
                    maxV = t;
                }
            }
        }
        if (pos == -1) {
            cout << pos << "\n";
            return;
        }
        swap(buff[len-1], buff[len - 1 - maxV.p]);
        printf("%s\n", buff);
    }    
};

antonCurrency t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
