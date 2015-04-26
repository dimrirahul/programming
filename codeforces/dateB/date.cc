#include <iostream>
#include <cmath>
#include <cstring>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;

typedef long long LL;
const int SZ = 101;

class date {

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    public:
        bool b[SZ], g[SZ];
        void start() {
            memset(b, 0, sizeof(bool) * SZ);
            memset(g, 0, sizeof(bool) * SZ);
            int n, m, s;
            cin >> n >> m;
            cin >> s;
            REP(i , s) {
                int t;
                cin >> t;
                b[t] = true;
            }
            cin >> s;
            REP(i, s) {
                int t;
                cin >> t;
                g[t] = true;
            }
            int lcm = n * m; 
            REP (i, lcm) {
                int bIdx = i % n;
                int gIdx = i % m;
                if (g[gIdx] || b[bIdx]) {
                    g[gIdx] = b[bIdx] = true;
                }
            }
            bool res = true;
            REP (i, n) {
                if (!b[i]) {
                    res = false;
                    break;
                }
            }

            if (res) {
                REP (i, m) {
                    if (!g[i]) {
                        res = false;
                        break;
                    }
                }
            }
            if (res) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }

        }    
};

date t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
