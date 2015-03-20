#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 26;
const int modbase = (int)1e9 + 7;
class dnaAlignment {
public:

    int fq[SZ];
    int pow(int b, int e) {
        LL res = 1;
        REP(i, e) {
            res *= b;
            res %= modbase; 
        }
        return (int)res;
    }
    void start() {
        REP(i, 26) fq[i] = 0;
        int t;
        cin >> t;
        string s;
        cin >> s;
        REPU(i, s.size()) fq[s[i] - 'A']++;
        int mx = 0;
        int res = 0;
        REP(i, 26) mx = max(mx, fq[i]);
        REP(i, 26) {
            if (fq[i] == mx) res++;
        }
        res = pow(res, s.size());
        cout << res << "\n";
    }    
};

dnaAlignment t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
