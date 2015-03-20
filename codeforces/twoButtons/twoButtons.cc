#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
class twoButtons {
public:
    int solve(int n, int m) {
        if (n == m) return 0;
        if (n > m) return n-m;
        if ( m % 2 == 1) return 1 + solve(n, m + 1);
        return 1 + solve (n, m/2);
    }
    void start() {
        int t1, t2;
        cin >> t1 >> t2;
        int v = solve(t1, t2);
        cout << v << "\n";
    }    
};

twoButtons t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
