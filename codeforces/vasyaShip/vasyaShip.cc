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
class vasyaShip {
public:

    LL getAns(LL a, LL b) {
        if ( a == b ) return 1;
        if (a < b) swap(a, b);
        LL eq = a / b;
        LL rem = a % b;
        if (rem  == 0) return eq;
        return eq + getAns(rem, b);
    }
    void start() {
        LL a, b;
        cin >> a >> b;
        cout << getAns(a, b) << "\n";
    }    
};

vasyaShip t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
