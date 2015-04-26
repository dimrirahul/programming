#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 100;
class teamTraining {
    public:
        void start() {
            int n, m, res = 0;
            cin >> n >> m;
            while (n > 0 && m > 0) {
                if (m > n) {
                    n--;
                    m -= 2;
                } else if (m < n) {
                    m--;
                    n -= 2;
                } else {
                    if ( m >= 2) {
                        m -= 2;
                        n--;
                    } else {
                        break;
                    }
                }
                res++;
            }
            cout << res << "\n";
        }    
};

teamTraining t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
